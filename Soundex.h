#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

// Lookup table for Soundex codes for 'A' to 'Z'.
char soundexMap[26] = {
    '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', // A-J
    '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', // K-T
    '0', '1', '0', '2', '0', '2'                      // U-Z
};

// Function to get Soundex code from the lookup table
char getSoundexCode(char c) {
    c = toupper(c);
    return (c >= 'A' && c <= 'Z') ? soundexMap[c - 'A'] : '0';
}

// Helper function to add a character to the Soundex code, if valid
void addToSoundex(char *soundex, char code, int *sIndex) {
    if (code != '0' && code != soundex[*sIndex - 1]) {
        soundex[(*sIndex)++] = code;
    }
}

// Helper function to initialize Soundex code
void initializeSoundex(const char *name, char *soundex, int *sIndex) {
    soundex[0] = toupper(name[0]);  // Start with the first letter capitalized
    *sIndex = 1;  // Initialize the index to the second character
}

// Helper function to pad remaining characters with '0'
void padSoundex(char *soundex, int *sIndex) {
    while (*sIndex < 4) {
        soundex[(*sIndex)++] = '0';
    }
    soundex[4] = '\0';  // Null-terminate the Soundex code
}

// Function to generate the Soundex code
void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    int sIndex = 0;  // Index to keep track of Soundex code position
    
    initializeSoundex(name, soundex, &sIndex);  // Initialize Soundex with first character

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        addToSoundex(soundex, code, &sIndex);  // Add valid code to Soundex
    }

    padSoundex(soundex, &sIndex);  // Pad with '0's to make it of length 4
}

#endif // SOUNDEX_H
