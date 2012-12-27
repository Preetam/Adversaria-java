test: src/main.c
	$(CC) $^ -std=c99 -o bin/advs

run:
	./bin/advs

check:
	cat db.advs | hexdump -v -e '"\\\x" 1/1 "%02x" " "'

.PHONY: test
