#include <stdio.h>
#include <string.h> 

extern void xexec_extern(unsigned char *command);

main(int argc, char *argv[]) {
    // basic11 "LOAD-FTD":<$C0>"FTDOS376.SYS"<$00><$xx><$00>
	char cmd[]={ 'b', 'a', 's', 'i', 'c',  '1', '1',' ','\"', 'L','O','A','D','-','F','T','D','\"',':', 0xc0,'\"','F','T','D','O','S','3','7','6','.','S','Y','S','\0','\0','\0','\0','\0','\0' };
    xexec_extern(cmd); // 
    
}
