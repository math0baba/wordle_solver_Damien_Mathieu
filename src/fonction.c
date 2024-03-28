#include "../include/wordle.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h> 
#include <string.h>
#define NBMOTS 2309
#define Len_Mot 6


void Tab_mots(char Mots[][Len_Mot]) {
    FILE* Fichier = fopen("../ressource/bdd_wordle.txt", "r");
    
    int iMot = -1;
    for (char Car = 'A'; Car <= 'Z'; Car++) { 
		
		if ( Car == 'X' ) continue; 
		
		while ( (fgetc(Fichier) != Car) || (fgetc(Fichier) != 13) ); 
		
		for (int i = 0; i < 7; i++) 
            fgetc(Fichier); 
		
		do {
			iMot += 1;
			fgets(Mots[iMot], Len_Mot, Fichier); 
			fgetc(Fichier); 
		} while ( isalpha(Mots[iMot][0]) ); 
		
		iMot -= 1; 
	}
	
	fclose(Fichier);

}


void filtrerLettresDebut(char Mots[][Len_Mot], char *lettres) {
    for (int i = 0; i < NBMOTS; i++) {
        if (strncmp(Mots[i], lettres, strlen(lettres)) != 0) {
            // Le mot ne commence pas par les lettres spécifiées, le marquer pour suppression
            Mots[i][0] = '\0';
        }
    }
}

void filtrerRetraitLettres(char Mots[][Len_Mot], char *lettres) {
    for (int i = 0; i < NBMOTS; i++) {
        int j;
        for (j = 0; Mots[i][j] != '\0'; j++) {
            if (strchr(lettres, Mots[i][j]) != NULL) {
                Mots[i][0] = '\0';
                break;
            }
        }
    }
}

void filtrerAjoutLettres(char Mots[][Len_Mot], char *lettres) {
    for (int i = 0; i < NBMOTS; i++) {
        int j;
        int contientLettres = 0;
        for (j = 0; Mots[i][j] != '\0'; j++) {
            if (strchr(lettres, Mots[i][j]) != NULL) {
                contientLettres = 1;
                break;
            }
        }
        if (!contientLettres) {
            Mots[i][0] = '\0';
        }
    }
}

void filtrerSuiteLettres(char Mots[][Len_Mot], char *suiteLettres) {
    for (int i = 0; i < NBMOTS; i++) {
        if (strstr(Mots[i], suiteLettres) == NULL) {
            Mots[i][0] = '\0';
        }
    }
}
