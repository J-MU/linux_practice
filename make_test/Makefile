.PHONY: clean

main : play_again1.o play_again2.o play_again3.o play_again0.o
	gcc play_again1.o -o play_again1
	gcc play_again2.o -o play_again2
	gcc play_again3.o -o play_again3
	gcc play_again0.o -o play_again0

play_again0.o : play_again0.c
	gcc -c play_again0.c

play_again1.o : play_again1.c
	gcc -c play_again1.c

play_again2.o : play_again2.c
	gcc -c play_again2.c

play_again3.o : play_again3.c
	gcc -c play_again3.c

clean:
	rm -f play_again1.o play_again1
	rm -f play_again2.o play_again2
	rm -f play_again3.o play_again3
	rm -f play_again0.o play_again0
