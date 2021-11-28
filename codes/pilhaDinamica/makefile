TARGET = prog

$(TARGET): main.o lib.a
	gcc $^ -o $@

main.o: main.c
	gcc -c $< -o $@

lib.a: dynamicStack.o
	ar rcs $@ $^

dynamicStack.o: dynamicStack.c dynamicStack.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)