CC = gcc
CFLAGS = 

run:
	@$(CC) $(CFLAGS) recaman.c -o output
	#@./output

clean:
	@rm output
