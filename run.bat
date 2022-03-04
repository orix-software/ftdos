@echo off

SET ORICUTRON="D:\Users\plifp\Onedrive\oric\oricutron_twilighte"





SET ORIGIN_PATH=%CD%


%CC65%\cl65.exe -ttelestrat src/main.c src/exec.s -o ftdos

IF "%1"=="NORUN" GOTO End
copy ftdos %ORICUTRON%\sdcard\bin\ftdos > NUL
rem copy ftdos /s/bin > NUL
cp ftdos /s/bin 


cd %ORICUTRON%

oricutron

:End
cd %ORIGIN_PATH%

