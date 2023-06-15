#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *nol;
	ssize_t o;
	ssize_t w;
	ssize_t r;

	o = open(filename, O_RDONLY);
	if (o == -1)
		return (0);
	nol = malloc(sizeof(char) * letters);
	r = read(o, nol, letters);
	w = write(STDOUT_FILENO, nol, r);

	free(nol);
	close(o);
	return (w);
}

