TARGET = prog

$(TARGET): main.o lib.a
	gcc $^ -o $@

main.o: main.c
	gcc -c $< -o $@

lib.a: staticQueue.o
	ar rcs $@ $^

staticQueue.o: staticQueue.c staticQueue.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)