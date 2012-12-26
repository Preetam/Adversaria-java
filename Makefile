test: src/main.c
	$(CC) $^ -std=c99 -o bin/advs
	./bin/advs

.PHONY: test
