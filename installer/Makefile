all: installer

installer: main.o
	gcc main.o $(shell pkg-config --libs gtk4) -o installer


%.o:src/%.c
	$(CC) $(CFLAGS) $(shell pkg-config --cflags --libs gtk4) -c $< -o $@
