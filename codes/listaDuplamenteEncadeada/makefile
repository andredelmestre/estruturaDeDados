TARGET = prog

$(TARGET): main.o lib.a
	gcc $^ -o $@

main.o: main.c
	gcc -c $< -o $@

lib.a: doubleLinkedList.o
	ar rcs $@ $^

doubleLinkedList.o: doubleLinkedList.c doubleLinkedList.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)