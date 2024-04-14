Clone of the popular mini-game wordle in C, taking the word to be guessed as a positional argument, and giving the user six attempts to guess the correct word, each guess is returned back to the user colored similarly to wordle - letters in a correct position are colored green, letters which are present in the word to be guessed but not in the correct position are colored yellow, and letters which do not exist in the word are left white.

The string to be guessed must be at most 34 characters in length (to accomodate the longest 'word' supercalifragilisticexpialidocious), no check is done to verify whether this condition is satisfied.

I'd like to make it possible to run the program with no command line arguments, and grab a 5 letter word randomly from a predefined dictionary of words to use as the word to be guessed.
