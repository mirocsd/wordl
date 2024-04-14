#include <stdio.h>
#include <string.h>
const char * const GREEN = "\x1b[32m";
const char * const YELLOW = "\x1b[33m";
const char * const WHITE = "\x1b[0m";
const char * current = WHITE;

void setColour(const char *colour) {
  if (current == colour) return;
  printf("%s", colour);
  current = colour;
}


void printColored(char *guess, char *actual) {
	int strlength = strlen(actual);
	char temp[34];
	int arr[34] = {0};
	int found[34] = {0};
	strcpy(temp, actual);

	for (int i=0; i<strlength; i++) {
		arr[i] = 0;
	}
	// first pass, check for correct position, update to '2'
	for (int i=0; i<strlength; i++) {
		if (guess[i]==actual[i]) {
			arr[i] = 2;
			found[i] = 1;
		}
	}
	// second pass, check for existence, update to '1'
	for (int i=0; i<strlength; i++) {
		if (arr[i] != 2) {
			for (int j=0; j<strlength; j++) {
				if (guess[i] == actual[j] && !found[j] && arr[i] != 1) {
					arr[i] = 1;
					found[j] = 1;
					break;
			}
		}
		}
		
	}
	// printing the output
	for (int i=0; i<strlength; i++) {
		if (arr[i] == 2) {
			setColour(GREEN);
			printf("%c", guess[i]);
		} else if (arr[i] == 1) {
			setColour(YELLOW);
			printf("%c", guess[i]);
		} else if (arr[i] == 0) {
			setColour(WHITE);
			printf("%c", guess[i]);
		}
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Invalid number of command line arguments\n");
		return 1;
	}
	char to_find[34];
	strcpy(to_find, argv[1]);

	char str[34];
	int i = 0;
	int max_guesses = 6;

	for (i=0; i<max_guesses; i++) {
		setColour(WHITE);
		printf("Enter guess: ");
		scanf(" %s", str);
		if (strlen(str) != strlen(to_find)) {
			printf("Invalid guess, guess length must match word length\n");
			return 1;
		}

		printColored(str, to_find);

		if (strcmp(str, to_find) == 0) {
			setColour(WHITE);
			printf("Finished in %d guesses\n", i+1);
			return 0;
		}
	}
	setColour(WHITE);
	printf("Failed to guess the word: %s\n", to_find);
	return 0;

}


