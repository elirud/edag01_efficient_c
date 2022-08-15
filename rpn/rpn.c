#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N		(10)

int stack[N];
int last = -1;
int line = 1;

int is_empty() {
	if (last == -1) {
		return 1;
	}
	return 0;
}

int is_full() {
	if (last == N-1) {
		return 1;
	}
	return 0;
}

bool push(int v) {
	if (is_full()) {
		return false;
	}
	stack[last+1] = v;
	last++;

	return true;
}

int pop() {
	int tmp = stack[last];
	stack[last] = 0;
	last--;

	return tmp;
}

void next_line(int c) {
	while ((c = getchar()) != '\n') {
	}
	last = -1;
	line++;
}

void p_err(int c) {
	printf("line %d: error at %c\n", line, c);
	next_line(c);
	return;
}

void do_math(int c) {

	if (last < 1) {
		p_err(c);
		return;
	}

	int opp = pop();
	int op = pop();
	bool r = false;

	if (c == '+') {
		r = push(op + opp);
	}
	else if (c == '-') {
		r = push(op - opp);
	}
	else if (c == '*') {
		r = push(op * opp);
	}
	else if (c == '/') {
		if (opp == 0) {
			p_err(c);
			return;
		}

		r = push(op / opp);
	}

	if (r == false) {
		p_err(c);
	}

}

int main(void)
{

	int c = 0;
	int num = 0;
	int num_built = 0;

	while ((c = getchar()) != EOF) {

		if (isdigit(c)) {
			num = (num * 10) + (c - '0');
			num_built = 1;
		}
		else if (isspace(c)) {
			if (c == '\n') {
				if (last != 0 || num_built == 1) {
					printf("line %d: error at \\n\n", line);
				}
				else {
					printf("line %d: %d\n", line, stack[0]);
				}
				num = 0;
				num_built = 0;
				last = -1;
				line++;
				continue;
			}
			else {
				if (num_built) {
					if (!push(num)) {
						printf("line %d: error at %d\n", line, num);
						next_line(c);
						last = -1;
					}
				}
				num = 0;
				num_built = 0;
			}
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			if (num_built) {
				push(num);
			}
			num = 0;
			num_built = 0;
			do_math(c);
		}
		else {
			p_err(c);
		}
	}

	return 0;
}
