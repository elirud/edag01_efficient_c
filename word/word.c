#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	int max = 0;
	int curr = 0;
	int c = 0;

	char* longest_word_array_p = malloc(sizeof(char));
	char* current_word_array_p = malloc(sizeof(char));

	while ((c = getchar()) != EOF) {

		if (isalpha(c)) {

			if (curr > max) {
				current_word_array_p = realloc(current_word_array_p, sizeof(char)*curr+1);
			}

			current_word_array_p[curr] = c;
			curr++;

		} else {

			if (curr > max) {
				longest_word_array_p = realloc(longest_word_array_p, sizeof(char)*curr);
				max = curr;
				strcpy(longest_word_array_p, current_word_array_p);
			}
			
			curr = 0;

		}

	}

	printf("%d characters in longest word: %s\n", max, longest_word_array_p);

	free(longest_word_array_p);
	free(current_word_array_p);

	return 0;

}
