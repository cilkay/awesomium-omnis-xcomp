@echo off

Rem Change the following values
set QUELLDIR=C:\replace\with\your\path\awesomium-omnis-xcomp\build\release
set ZIELDIR=C:\Program Files (x86)\TigerLogic\OS4321\xcomp

xcopy "%QUELLDIR%\webLib.dll" "%ZIELDIR%" /y
if %errorlevel% neq 0 exit /b %errorlevel%

pause