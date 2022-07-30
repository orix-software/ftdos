#include <stdio.h>
#include <string.h> 

extern void xexec_extern(unsigned char *command);

void version() {
	printf("v2022.3\n");
}


int main(int argc, char *argv[]) {
    // basic11 "LOAD-FTD":<$C0>"FTDOS376.SYS"<$00><$xx><$00>
	unsigned char cmd[]={ 'b', 'a', 's', 'i', 'c',  '1', '1',' ','\"', 'L','O','A','D','-','F','T','D','\"',':', 0xc0,'\"','F','T','D','O','S','3','7','6','.','S','Y','S','\"',',','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };

    if (argc==2) {
		if (strcmp(argv[1],"-v")==0) {
			version();
			return 0;
		}

        strcat(cmd,",\"");
        strcat(cmd,strupper(argv[1]));
        strcat(cmd,"\"");
    }

    xexec_extern(cmd); //
	return 0;
}
