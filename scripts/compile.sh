gcc -o run \
../src/main.c \
../src/execute_commands.c \
../src/commands/pwd.c \
../src/commands/clear.c \
../src/commands/ls.c \
../src/commands/mkdir.c \
../src/commands/rmdir.c \
../src/commands/cd.c \
../src/commands/rm.c \
../src/commands/touch.c \
../src/commands/man.c \
../src/commands/cat.c \
../src/commands/echo.c \
../src/commands/grep.c \
../src/commands/cp.c \
../src/commands/mv.c \
../src/commands/chmod.c \
-I ../include \
-Wall

if [ $? -eq 0 ]; then
    echo "Compilation successful. Run the program with ./run"
else
    echo "Compilation failed."
fi