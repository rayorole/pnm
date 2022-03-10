install: main.c
	gcc -o pnm main.c -I.
	sudo mv pnm /usr/local/bin/pnm

clean:
	rm -rf pnm