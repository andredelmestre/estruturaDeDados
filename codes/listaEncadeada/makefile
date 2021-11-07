TARGET = prog

$(TARGET): main.o lib.a
	gcc $^ -o $@

main.o: main.c
	gcc -c $< -o $@

lib.a: dynamicList.o
	ar rcs $@ $^

dynamicList.o: dynamicList.c dynamicList.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)