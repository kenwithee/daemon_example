CC=gcc
CFLAGS=-Wall
BACKUPFILE := $(shell date +%Y-%m-%d_%H-%M-%S)_daemon_1_backup.tar.gz

all: daemon_1.c
	$(CC) daemon_1.c -o daemon_1

run: 
	./daemon_1

backup: Makefile daemon_1.c
	tar -zcvf backups/$(BACKUPFILE) Makefile daemon_1.c

clean:
	rm daemon_1
