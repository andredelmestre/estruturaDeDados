TARGET = prog

$(TARGET): main.o lib.a
	gcc $^ -o $@

main.o: main.c
	gcc -c $< -o $@

lib.a: circularLinkedList.o
	ar rcs $@ $^

circularLinkedList.o: circularLinkedList.c circularLinkedList.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)