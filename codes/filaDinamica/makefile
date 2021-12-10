TARGET = prog

$(TARGET): main.o lib.a
	gcc $^ -o $@

main.o: main.c
	gcc -c $< -o $@

lib.a: dynamicQueue.o
	ar rcs $@ $^

dynamicQueue.o: dynamicQueue.c dynamicQueue.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)