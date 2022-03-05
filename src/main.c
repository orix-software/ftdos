#include <stdio.h>
#include <string.h> 

extern void xexec_extern(unsigned char *command);
/*

La syntaxe devient:
    !["FTDOS376.SYS"][,"MONDSK"]

Le nom du fichier système devient optionnel et vaut FTDOS376.SYS par défaut
Le nom du fichier .dsk est optionnel et vaut FTDOS par défaut

On peut donc se contenter d'une commande ! pour lancer le ftdos avec un disque monté si il existe.
Si on veut ne préciser que le disque à monter, on peut se contenter de !,"MONDSK" (ne pas oublier la virgule)

*/

main(int argc, char *argv[]) {


    // basic11 "LOAD-FTD":<$C0>"FTDOS376.SYS"<$00><$xx><$00>
	char cmd[]={ 'b', 'a', 's', 'i', 'c',  '1', '1',' ','\"', 'L','O','A','D','-','F','T','D','\"',':', 0xc0,'\"','F','T','D','O','S','3','7','6','.','S','Y','S','\"','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0' };

    if (argc==2) {
        strcat(cmd,",\"");
        strcat(cmd,strupper(argv[1]));
        strcat(cmd,"\"");
        
    }

    xexec_extern(cmd); // 
    
}
