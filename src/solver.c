#include "fonction.c"


int main() {
    char Mots[NBMOTS][Len_Mot], lettres[Len_Mot];

    Tab_mots(Mots);

    printf("Liste de mots utilisables :\n");
    for (int i = 0; i < NBMOTS; i++) {
        printf("%s  ", Mots[i]);
    }
    printf("\n\n");

    int choix;
    int continuer = 1;
    while (continuer) {
        printf("Voulez-vous appliquer un filtre ? (1 pour Oui, 0 pour Non) : ");
        scanf("%d", &choix);
        if (choix == 1) {
            printf("Choisissez le filtre à appliquer (1-4) : \n    1. Ajout de lettres \n    2. Retrait de lettres \n    3. Suite de lettres \n    4. Commence par...\n");
            scanf("%d", &choix);


            switch (choix) {
                case 1:
                    printf("Entrez les lettres qui sont dans le mot (en minuscules, sans espaces) : ");
                    scanf("%s", lettres);
                    for (int i = 0; lettres[i] != '\0'; i++)
                        lettres[i] = tolower(lettres[i]);
                    printf("\n");
                    filtrerAjoutLettres(Mots, lettres);
                    printf("Mots avec les lettres '%s' :\n", lettres);
                    for (int i = 0; i < NBMOTS; i++) {
                        if (Mots[i][0] != '\0') {
                            printf("%s  ", Mots[i]);
                        }
                    }
                    printf("\n\n");
                    break;


                case 2:
                    printf("Entrez les lettres à enlever (en minuscules, sans espaces) : ");
                    scanf("%s", lettres);
                    for (int i = 0; lettres[i] != '\0'; i++)
                        lettres[i] = tolower(lettres[i]);
                    printf("\n");
                    filtrerRetraitLettres(Mots, lettres);
                    printf("Mots sans les lettres '%s' :\n", lettres);
                    for (int i = 0; i < NBMOTS; i++) {
                        if (Mots[i][0] != '\0') {
                            printf("%s  ", Mots[i]);
                        }
                    }
                    printf("\n\n");
                    break;


                case 3:
                    printf("Entrez la suite de lettres présente dans le mot (en minuscules, sans espaces) : ");
                    scanf("%s", lettres);
                    for (int i = 0; lettres[i] != '\0'; i++)
                        lettres[i] = tolower(lettres[i]);
                    printf("\n");
                    filtrerSuiteLettres(Mots, lettres);
                    printf("Mots contenant la suite de lettres '%s' :\n", lettres);
                    for (int i = 0; i < NBMOTS; i++) {
                        if (Mots[i][0] != '\0') {
                            printf("%s  ", Mots[i]);
                        }
                    }
                    printf("\n\n");
                    break;


                case 4:
                    printf("Entrez la lettre ou la suite de lettres qui doivent commencer les mots : ");
                    scanf("%s", lettres);
                    for (int i = 0; lettres[i] != '\0'; i++)
                        lettres[i] = tolower(lettres[i]);
                    printf("\n");
                    filtrerLettresDebut(Mots, lettres);
                    printf("Mots commencant par '%s' :\n", lettres);
                    for (int i = 0; i < NBMOTS; i++) {
                        if (Mots[i][0] != '\0') {
                            printf("%s  ", Mots[i]);
                        }
                    }
                    printf("\n\n");
                    break;


                default:
                    printf("Filtre invalide.\n");
            }
        } else if (choix == 0) {
            continuer = 0;

        } else {
            printf("Choix invalide.\n");
        }
    }

    return 0;
}
