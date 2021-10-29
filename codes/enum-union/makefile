TARGET = prog

$(TARGET): main.o lib.a
	gcc $^ -o $@

main.o: main.c
	gcc -c $< -o $@

lib.a: struct.o
	ar rcs $@ $^

struct.o: struct.c struct.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)