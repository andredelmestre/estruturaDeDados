TARGET = prog

$(TARGET): main.o lib.a
	gcc $^ -o $@

main.o: main.c
	gcc -c $< -o $@

lib.a: staticStack.o
	ar rcs $@ $^

staticStack.o: staticStack.c staticStack.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)