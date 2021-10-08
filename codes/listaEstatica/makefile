TARGET = prog

$(TARGET): main.o lib.a
	gcc $^ -o $@

main.o: main.c
	gcc -c $< -o $@

lib.a: staticList.o
	ar rcs $@ $^

staticList.o: staticList.c staticList.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)