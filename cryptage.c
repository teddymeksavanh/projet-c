#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int fonctionChoixDuCryptage (int premiereBorne, int deuxiemeBorne) //Cette fonction permet de determiner quelle méthode de cryptage sera utilisée
{
        return rand()%(deuxiemeBorne-premiereBorne) +premiereBorne;
}

char cryptageCesar (caractereEnCours)
{
    /* Si le caractere est une minuscule */
    if ('a' <= caractereEnCours && caractereEnCours <= 'z')
        caractereEnCours = 'a' + ((caractereEnCours - 'a') + 13)%26;
    else
        /* Si le caractere est une majuscule */
    if ('A' <= caractereEnCours && caractereEnCours <= 'Z')
        caractereEnCours = 'A' + ((caractereEnCours - 'A') + 13)%26;
    else
        /* Si le caractere est un chiffre */
    if ('0' <= caractereEnCours && caractereEnCours <= '9')
        caractereEnCours = '0' + ((caractereEnCours - '0') + 13)%10;

    return caractereEnCours;
}

char decryptageCesar (caractereEnCours)
{
        /* Si le caractere est une minuscule */
        if ('a' <= caractereEnCours && caractereEnCours <= 'z')
            caractereEnCours = 'z' + ((caractereEnCours - 'z') - 13)%26;
        else
            /* Si le caractere est une majuscule */
        if ('A' <= caractereEnCours && caractereEnCours <= 'Z')
            caractereEnCours = 'Z' + ((caractereEnCours - 'Z') - 13)%26;
        else
            /* Si le caractere est un chiffre */
        if ('0' <= caractereEnCours && caractereEnCours <= '9')
            caractereEnCours = '0' + ((caractereEnCours - '0') - 13)%10;
}

char applicationCryptageCaractere (char caractereEnCours, int premiereBorne, int deuxiemeBorne) //Cette fonction contiendra l'ensemble des méthodes de cryptage du prgramme
{
    int choixDuCryptage = fonctionChoixDuCryptage(premiereBorne, deuxiemeBorne);
    switch (choixDuCryptage)
    {
        case 1:
            ecritureFichierDecryptage(choixDuCryptage);

            //ajouter l'appel à la fonction de cryptage du fichier
            break;
        case 2:
            ecritureFichierDecryptage(choixDuCryptage);
            caractereEnCours = cryptageCesar(caractereEnCours);
            break;
        case 3:
            ecritureFichierDecryptage(choixDuCryptage);
            break;
        case 4:
            ecritureFichierDecryptage(choixDuCryptage);
            break;
        case 5:
            ecritureFichierDecryptage(choixDuCryptage);
            break;
        case 6:
            ecritureFichierDecryptage(choixDuCryptage);
            break;
        case 7:
            ecritureFichierDecryptage(choixDuCryptage);
            break;
        case 8:
            ecritureFichierDecryptage(choixDuCryptage);
            break;
        case 9:
            ecritureFichierDecryptage(choixDuCryptage);
            break;
        default:
            puts("Ce cryptage n'est pas disponible");
            break;
    }
        return caractereEnCours;
}

char applicationDecryptageCaractere (char caractereEnCours, int methodeDeDecryptage) //Cette fonction contiendra l'ensemble des méthodes de decryptage du programme
{
    int choixDuDecryptage = methodeDeDecryptage;
    switch (choixDuDecryptage)
    {
        case 1:
            //puts("Methode 1");
            break;
        case 2:
            //puts("Methode 2");
            break;
        case 3:
            //puts("Methode 3");
            break;
        case 4:
            //puts("Methode 4");
            break;
        case 5:
            //puts("Methode 5");
            break;
        case 6:
            //puts("Methode 6");
            break;
        case 7:
           // puts("Methode 7");
            break;
        case 8:
            //puts("Methode 8");
            break;
        case 9:
            puts("Methode 9");
            break;
        default:
            puts("Ce decryptage n'est pas disponible");
    }
    return caractereEnCours;
}

void ecritureFichierDecryptage (int choixDuCryptage) //cette procédure écrira dans le fichier decryptage.txt la clé nécessaire au décryptage des informations
{
    FILE* fichier2 = NULL;

    fichier2 = fopen("decryptage.txt", "a");

    if (fichier2 != NULL)
    {
        fprintf(fichier2,"%d",choixDuCryptage); // Écriture du caractère contenu dans choixDuCryptage
        fclose(fichier2);
    }
}

int lectureFichierDecryptage (long positionCaractereEnCours)
{
    FILE* fichier2 = NULL;
    char temporaire[1];
    char caractereActuel;
    int methodeDeDecryptage;

    fichier2 = fopen("decryptage.txt", "r");

    if (fichier2 != NULL)
    {
        fseek(fichier2, positionCaractereEnCours, SEEK_SET);
        //printf("La position du curseur est la suivante : %ld \n", positionCaractereEnCours);

        caractereActuel = fgetc(fichier2);
        sprintf(temporaire,"%c",caractereActuel);
        methodeDeDecryptage = atoi(temporaire);
        //printf("La donnee contenue a cette adresse est la suivante : %c \n\n", caractereActuel);
        fclose(fichier2);
    }

    //printf("La variable methodeDeDecryptage dans lectureFichierDecryptage vaut : %d \n", methodeDeDecryptage);

    return methodeDeDecryptage; //retourne le numéro de la méthode de cryptage à utiliser pour le caractère positionCaractereEnCours
}

void cryptageDuFichier (char caractereEnCours, int premiereBorne, int deuxiemeBorne) //Cette procédure servira à appeler l'ensemble des autres procédures/fonction nécessaires au cryptage du fichier
{
    FILE* fichier = NULL;
    //int caractereActuel = 0;

    fichier = fopen("Contact.txt", "r"); /* On ouvre le fichier en lecture seule */
    if (fichier != NULL)
    {
        do                               /* On crée une boucle afin de lire tous les caractères un par un, jusqu'à ce que le résultat contenu soit End Of File */
        {
            caractereEnCours = fgetc(fichier);
            printf("%c", applicationCryptageCaractere(caractereEnCours, premiereBorne, deuxiemeBorne));
        } while (caractereEnCours != EOF);
        fclose(fichier);
        printf("\n");
        puts("FIN DU CRYPTAGE DU FICHIER !");
    }
}

void decryptageDuFichier (char caractereEnCours, long positionCaractereEnCours)
{
    FILE* fichier = NULL;
    int methodeDeDecryptage;

    fichier = fopen("Contact.txt", "r"); /* On ouvre le fichier en lecture seule */
    if (fichier != NULL)
    {
        do
        {
            caractereEnCours = fgetc(fichier);
            methodeDeDecryptage = lectureFichierDecryptage(positionCaractereEnCours); //détermine la méthode de décryptage à utiliser pour décrypter le caractère caractereEnCours a la position positionCaractereEnCours
            positionCaractereEnCours += 1;
            applicationDecryptageCaractere(caractereEnCours, methodeDeDecryptage);
        } while (caractereEnCours != EOF);
    }
    fclose(fichier);
}

int main ()
{
    int premiereBorne = 1; //On souhaite que chaque caractère soit crypté entre 1
    int deuxiemeBorne = 9; //Et 9 fois
    long positionCaractereEnCours = 0;
    char caractereEnCours = ' ';
    srand(time(NULL)); //time() retourne le nombre de secondes écoulées depuis le 1er janvier 1970

    puts("Le fichier va maintenant etre crypte...");
    cryptageDuFichier(caractereEnCours, premiereBorne, deuxiemeBorne);

    caractereEnCours = ' ';
    puts("Le fichier va maintenant etre decrypte...");
    decryptageDuFichier(caractereEnCours, positionCaractereEnCours);

    return 0;
}
