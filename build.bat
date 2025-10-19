@echo off
echo Compiling project...

REM Compile all source files WILL ADD YOUR FILES TO THIS BEFORE TRYING TO BUILD!!!!!!!!!!
g++ spammerMain.cpp -IC:/mingw64/include -ICore -LC:/mingw64/lib -lopengl32 -lgdi32 -lglu32 -o spammer.exe

if %ERRORLEVEL% neq 0 (
    echo Build failed!
    pause
    exit /b %ERRORLEVEL%
)

echo Build successful! Output: spammer.exe
pause