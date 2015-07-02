#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>

float get_internal_distance(char ** strings, unsigned nstrings, unsigned slen);
unsigned hamming_n(char * s1, char * s2, unsigned len);

float get_internal_distance(char ** strings, unsigned nstrings, unsigned slen)
{
    if (nstrings == 0)
    {
        return -1.0f;
    }
    else if (nstrings == 1)
    {
        return 0.0f;
    }

    unsigned tot = 0;
    unsigned n   = 0;
    unsigned i, ii;
    for (i = 0; i < nstrings; i++)
    {
        for (ii = i+1; ii < nstrings; ii++)
        {
            tot += hamming_n(strings[i], strings[ii], slen);

            n++;
        }
    }

    return ((float) tot) / (slen * n);
}

unsigned hamming_n(char * s1, char * s2, unsigned slen)
{
    unsigned count = 0;
    
    for (unsigned i = 0; i < slen; i++)
    {
        if (s1[i] != s2[i] && s1[i] != 'N' && s2[i] != 'N')
            count++;
    }

    return count;
}