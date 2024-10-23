CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = $(shell find . -name count_and_say.c)

PROGRAMS = $(patsubst %/count_and_say.c, %/count_and_say, $(SOURCES))

ARGS = abc 123 ABBCCCDDD \\t \\n 9999999999999999999999999999 -1000000 0000 DONTPANIC! .///

.PHONY: all clean run

all:
	@output_file="output.txt"; \
	echo "Compiling programs..."; \
	for prog in $(PROGRAMS); do \
		-$(CC) $(CFLAGS) -o $$prog $$prog.c 2>/dev/null || true; \
	done; \
	echo "Compiling done, run 'make run'"

%/count_and_say: %/count_and_say.c
	@-$(CC) $(CFLAGS) -o $@ $< 2>/dev/null || true

clean:
	rm -f $(PROGRAMS)

run: $(PROGRAMS)
	@output_file="output.txt"; \
	echo "" >> $$output_file; \
	for prog in $(PROGRAMS); do \
		if [ -f $$prog ]; then \
			src=$${prog%/*}/count_and_say.c; \
			echo "Norminette output for $$src:" >> $$output_file; \
			norminette $$src >> $$output_file; \
			echo "" >> $$output_file; \
			echo "Running $$prog with arguments:" >> $$output_file; \
			for arg in $(ARGS); do \
				echo "    Argument passed: $$arg" >> $$output_file; \
				output=$$(./$$prog $$arg); \
				echo "    Program Output: $$output" >> $$output_file; \
				echo "" >> $$output_file; \
			done; \
			echo "_______________________________" >> $$output_file; \
			echo "" >> $$output_file; \
		else \
			echo "$$prog not found. Skipping..." >> $$output_file; \
		fi; \
	done; \
	echo "Output written to $$output_file"; \
	open $$output_file
