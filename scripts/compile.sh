gcc -o run \
../src/main.c \
../src/execute_commands.c \
../src/commands/pwd.c \
../src/commands/clear.c \
../src/commands/ls.c \
../src/commands/mkdir.c \
../src/commands/rmdir.c \
-I ../include \
-Wall

if [ $? -eq 0 ]; then
    echo "Compilation successful. Run the program with ./run"
else
    echo "Compilation failed."
fi