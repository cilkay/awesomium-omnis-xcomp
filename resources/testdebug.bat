@echo off

Rem Change the following
set QUELLDIR=C:\replace\with\your\path\awesomium-omnis-xcomp\build\debug
set ZIELDIR=C:\Program Files (x86)\TigerLogic\OS4321\xcomp

xcopy /y "%QUELLDIR%\webLib.dll" "%ZIELDIR%"
if %errorlevel% neq 0 exit /b %errorlevel%
xcopy /y "%QUELLDIR%\webLib.pdb" "%ZIELDIR%"
if %errorlevel% neq 0 exit /b %errorlevel%

