binary: synch_exercise.c
	gcc $< -pthread -o $@

.PHONY: run clean

run:
	./binary

clean:
	rm binary