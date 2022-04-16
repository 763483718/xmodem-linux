/*
	Copyright 2001, 2002 Georges Menie (www.menie.org)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* this code needs standard functions memcpy() and memset()
   and input/output functions port_inbyte() and port_outbyte().

   the prototypes of the input/output functions are:
     int port_inbyte(unsigned short timeout); // msec timeout
     void port_outbyte(int c);

 */




static int last_error = 0;
/****************Portting Start *******************/



#include "xmodem.hpp"

void port_outStream(unsigned char* stream, int size)
{
    lowLevel_write(stream, size);
}

int port_inStream(unsigned char* stream,int size, int time_out)
{
    return lowLevel_read(stream, size, time_out);
}

void port_outbyte(unsigned char trychar)
{
	unsigned char buf[2];
	buf[0] = trychar;
	lowLevel_write(buf,1);
}

unsigned char port_inbyte(unsigned int time_out)
{
	unsigned char ch;
	int i;
	last_error = 0;

	if(lowLevel_read(&ch,1,time_out) > 0)
    {
        char temp = (char)(ch);
        // std::cout << ch << std::endl;
        return ch;
    }
		

	last_error = 1;
	return ch;
}
/****************Portting End*******************/
static int check(int crc, const unsigned char *buf, int sz)
{
	if (crc) 
	{
		unsigned short crc = crc16_ccitt(buf, sz);
		unsigned short tcrc = (buf[sz]<<8)+buf[sz+1];
		if (crc == tcrc)
			return 1;
	}
	else 
	{
		int i;
		unsigned char cks = 0;
		for (i = 0; i < sz; ++i) 
		{
			cks += buf[i];
		}
		if (cks == buf[sz])
		return 1;
	}

	return 0;
}

static void flushinput(int count = -1)
{
    if(count == -1) return ;
    for(int i = 0;i < count;++i)
    {
        std::cout << test_buf[i];
    }
    // std::cout << std::endl;
    std::cout << std::endl << count << std::endl;
    // std::cout << "flush:" << test_buf[1] << std::endl;
    // printf("flush:\t%s\n", (char*)test_buf);
}

int xmodemReceive(unsigned char *dest, int destsz)
{
    // char dev[] = "/dev/ttyUSB0";
    // char dev[] = "/dev/ttyS0";
    // open_port(dev);
    // port_outbyte('C');
    // while(1)
    // {
    //     usleep(200);
    // }

    if(dest == 0)
    {
        return -4;
    }
    test_buf = dest;

	unsigned char xbuff[1030]; /* 1024 for XModem 1k + 3 head chars + 2 crc + nul */
	unsigned char *p;
	int bufsz, crc = 0;
	unsigned char trychar = 'C';
	unsigned char packetno = 1;
	int i, len = 0;
    unsigned char c;
	int retry, retrans = MAXRETRANS;

	for(;;) 
	{
        bool break_flag = false;
		for( retry = 0; retry < 16; ++retry) 
		{
			if(trychar)
            {
                port_outbyte(trychar);
            }
			c = port_inbyte((DLY_1S)<<1);
			if(last_error == 0) 
			{
				switch (c)
				{
					case SOH:
                        std::cout << "\n128mode\t" << (int)packetno << std::endl;
						bufsz = 128;
						break_flag = true;
                        break;
					case STX:
                        std::cout << "\n1024mode\t" << (int)packetno << std::endl;
						bufsz = 1024;
						break_flag = true;
                        break;
					case EOT:
                        std::cout << "finished\n";
						flushinput();
						port_outbyte(ACK);
						return len; /* normal end */
					case CAN:
						c = port_inbyte(DLY_1S);
						if (c == CAN) 
						{
							flushinput();
							port_outbyte(ACK);
							return -1; /* canceled by remote */
						}
						break;
					default:
						break;
				}
			}
            if(break_flag)
            {
                break;
            }
		}
        if(!break_flag)
        {
            if (trychar == 'C') 
            { 
                trychar = NAK; 
                continue; 
            }
            flushinput();
            port_outbyte(CAN);
            port_outbyte(CAN);
            port_outbyte(CAN);
            return -2; /* sync error */
        }
        //开始接收packet
		if (trychar == 'C') 
        {
            crc = 1;
        }
		trychar = 0;
		p = xbuff;
		*p++ = c;


		// for (i = 0;  i < (bufsz+(crc?1:0)+3); ++i) 
		// {
		// 	c = port_inbyte(DLY_1S);
        //     // std::cout << c << std::endl;
		// 	if (last_error != 0)
        //     {
        //         // flushinput();
        //         port_outbyte(NAK);
        //     }
		// 	*p++ = c;
		// }

        int ret = port_inStream(&xbuff[1], bufsz + (crc?1:0) + 3, 2000);
        if(ret == -1)
        {
            std::cout << "error in getStream\n";
            port_outbyte(NAK);
            continue;
        }

        // std::cout << "diff:\t" << p - xbuff << std::endl;
		if (xbuff[1] == (unsigned char)(~xbuff[2]) && 
			(xbuff[1] == packetno || xbuff[1] == (unsigned char)packetno-1) &&
			check(crc, &xbuff[3], bufsz)) 
		{
            std::cout << "check\n";
			if (xbuff[1] == packetno)
			{
				int count = destsz - len;
				if (count > bufsz) 
					count = bufsz;
                // std::cout << "destsz:\t" << destsz << std::endl;
                // std::cout << "len:\t" << len << std::endl;
				if (count > 0) 
				{
					memcpy(dest, &xbuff[3], count);
					len += count;
                    // flushinput(count);//count
				}
				++packetno;
				retrans = MAXRETRANS+1;
			}
			if (--retrans <= 0) 
			{
				flushinput();
				port_outbyte(CAN);
				port_outbyte(CAN);
				port_outbyte(CAN);
				return -3; /* too many retry error */
			}
            // std::cout << "outByte ACK\n";
			port_outbyte(ACK);
			continue;
		}else
        {
            if(xbuff[1] != (unsigned char)(~xbuff[2]))
            {
                std::cout << "not check 111\n";
                std::cout << (int)xbuff[1] << std::endl << std::endl;
            }
            if((xbuff[1] != packetno && xbuff[1] != (unsigned char)packetno-1) )
            {
                std::cout << "not check 222\n";
            }
            if(!check(crc, &xbuff[3], bufsz))
            {
                std::cout << "not check 333\n";
            }
        }
        
        
	}
}

int xmodemTransmit(unsigned char *src, int srcsz)
{
    // char dev[] = "/dev/ttyS0";
    // char dev[] = "/dev/ttyUSB0";
    // open_port(dev);
    
	unsigned char xbuff[1030]; /* 1024 for XModem 1k + 3 head chars + 2 crc + nul */
	int bufsz, crc = -1;
	unsigned char packetno = 1;
	int i, c, len = 0;
	int retry;

	for(;;) {
        bool break_flag = false;
		for( retry = 0; retry < 16; ++retry) 
		{
			c = port_inbyte((DLY_1S)<<1);
			if (last_error == 0) 
			{
				switch (c) 
				{
					case 'C':
                        std::cout << "get C\n";
						crc = 1;
                        break_flag = true;
						// goto start_trans;
                        break;
					case NAK:
                        std::cout << "get NAK\n";
						crc = 0;
                        break_flag = true;
						// goto start_trans;
                        break;
					case CAN:
						c = port_inbyte(DLY_1S);
						if (c == CAN) 
						{
							port_outbyte(ACK);
							flushinput();
							return -1; /* canceled by remote */
						}
						break;
					default:
						break;
				}
			}
            if(break_flag)
            {
                break;
            }
		}
        if(!break_flag)
        {
            port_outbyte(CAN);
            port_outbyte(CAN);
            port_outbyte(CAN);
            flushinput();
            return -2; /* no sync */
        }
        int ack_count = 0;
		for(;;) 
		{
		// start_trans:
			xbuff[0] = STX; bufsz = 1024;
			// xbuff[0] = SOH; bufsz = 128;
            
			xbuff[1] = packetno;
			xbuff[2] = ~packetno;
            std::cout << "set xbuff[1]= " << (int)xbuff[1] << std::endl;
			c = srcsz - len;
			if (c > bufsz) c = bufsz;
			if (c >= 0) 
			{
                // std::cout << "c:\t" << c << std::endl;
				memset (&xbuff[3], 0, bufsz);
				if (c == 0) 
				{
					xbuff[3] = CTRLZ;
				}
				else 
				{
					memcpy (&xbuff[3], &src[len], c);
					if (c < bufsz) xbuff[3+c] = CTRLZ;
				}
				if (crc) 
				{
					unsigned short ccrc = crc16_ccitt(&xbuff[3], bufsz);
					xbuff[bufsz+3] = (ccrc>>8) & 0xFF;
					xbuff[bufsz+4] = ccrc & 0xFF;
				}
				else 
				{
					unsigned char ccks = 0;
					for (i = 3; i < bufsz+3; ++i) 
					{
						ccks += xbuff[i];
					}
					xbuff[bufsz+3] = ccks;
				}
                bool succ_flag = false;
				for (retry = 0; retry < MAXRETRANS; ++retry) 
				{
                    // std::cout << "retry:\t" << retry << std::endl;
					// for (i = 0; i < bufsz+4+(crc?1:0); ++i) 
					// {
					// 	port_outbyte(xbuff[i]);
					// }
                    port_outStream(xbuff, bufsz+4+(crc?1:0));
					c = port_inbyte(DLY_1S);
                    // std::cout << "getReturn:\t" << temp << std::endl;
					if (last_error == 0 ) 
					{
						switch (c) 
						{
							case ACK:
								++packetno;
								len += bufsz;
                                succ_flag = true;
                                ++ack_count;
                                std::cout << "get ACK\t" << ack_count << std::endl;;
								// goto start_trans;
                                break;
							case CAN:
								c = port_inbyte(DLY_1S);
								if ( c == CAN) 
								{
									port_outbyte(ACK);
									flushinput();
                                    std::cout << "get CAN\n";
									return -1; /* canceled by remote */
								}
								break;
							case NAK:
                                std::cout << "get NAK\n";
							default:
								break;
						}
					}
                    if(succ_flag)
                    {
                        break;
                    }
				}
                if(!succ_flag)
                {
                    port_outbyte(CAN);
                    port_outbyte(CAN);
                    port_outbyte(CAN);
                    flushinput();
                    return -4; /* xmit error */
                }
			}
			else 
			{
				for (retry = 0; retry < 10; ++retry) 
				{
					port_outbyte(EOT);
					c = port_inbyte((DLY_1S)<<1);
					if (c == ACK) break;
				}
				flushinput();
				return (c == ACK)?len:-5;
			}
		}
	}
}
