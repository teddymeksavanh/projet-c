#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Tcontact
{
    char Nom[30];
    char Prenom[30];
    int Numero_voie[3];
    char Type_voie[10];
    char Nom_voie[50];
    char Ville[50];
    char Email[50];
    int Tel[10];
    int CP[5];
};
/* Fin de la structure */

/* D�but de la proc�dure */
void Ajout (struct Tcontact contact[100], int cpt)
{
    /* D�claration des variables. */
    FILE* fichier = NULL;
    int i,rep,j;
    i = -1;
    rep = 1;
    j = cpt + 1;
    /* Fin d�claration des variables. */

    while (rep == 1)
    {
        i = i + 1;
        cpt = cpt + 1;
        /* On saisie les diff�rentes informations caract�risant un contact. */
        printf("Veuillez saisir le nom :\n");
            fflush(stdin);
            gets(contact[cpt].Nom);

        printf("Veuillez saisir le prenom :\n");
            fflush(stdin);
            gets(contact[cpt].Prenom);

        printf("Veuillez saisir l'adresse :\n");
        printf("Numero de votre habitation :\n");
            fflush(stdin);
            gets(contact[cpt].Numero_voie);

        printf("Type de la voie ou vous habitez (rue, boulevard...) :\n");
            fflush(stdin);
            gets(contact[cpt].Type_voie);

            printf("Nom de la voie ou vous habitez :\n");
            printf("P.S : Sans espace, utiliser un - pour representer les espaces.\n");
            fflush(stdin);
            scanf("%s",&contact[cpt].Nom_voie);

        printf("Veuillez saisir le code postal :\n");
            fflush(stdin);
            gets(contact[cpt].CP);

        printf("Veuillez saisir la ville :\n");
            fflush(stdin);
            gets(contact[cpt].Ville);

        printf("Veuillez saisir l'adresse email :\n");
            fflush(stdin);
            gets(contact[cpt].Email);

        printf("Veuillez saisir le numero de telephone :\n");
            fflush(stdin);
            gets(contact[cpt].Tel);
            fprintf(fichier,"%s\n",contact[i].Tel);
        /* Fin de la saisie des informations */

        printf("Voulez vous saisir un autre contact ? (0 pour non / 1 pour oui)\n");
        scanf("%d",&rep);
        while (rep != 0 && rep != 1)
        {
            printf("Choix incorrect. Veuillez refaire votre choix.\n");
            fflush(stdin);
            scanf("%d",&rep);
        }
    }
    fichier = fopen("Contact.txt", "a");
    if (fichier != NULL)
    {
        for (i=j;i<=cpt;i++)
            {
                fprintf(fichier,"%s\n",contact[i].Nom);
                fprintf(fichier,"%s\n",contact[i].Prenom);
                fprintf(fichier,"%s ",contact[i].Numero_voie);
                fprintf(fichier,"%s ",contact[i].Type_voie);
                fprintf(fichier,"%s\n",contact[i].Nom_voie);
                fprintf(fichier,"%s\n",contact[i].CP);
                fprintf(fichier,"%s\n",contact[i].Ville);
                fprintf(fichier,"%s\n",contact[i].Email);
                fprintf(fichier,"%s\n",contact[i].Tel);
                fprintf(fichier,"\n");
            }
    fclose(fichier); /* On ferme le fichier */
    }
}
/* Fin de la proc�dure */

/* D�but de la proc�dure */

void Affichage (struct Tcontact contact[100])
{

    FILE* fichier = NULL;
    int caractereActuel = 0;

    fichier = fopen("Contact.txt", "r"); /* On ouvre le fichier en lecture seule */
    if (fichier != NULL)
    {
        do                               /* On cr�e une boucle afin de lire tous les caract�res un par un, jusqu'� ce que le r�sultat contenu soit End Of File */
        {
            caractereActuel = fgetc(fichier);
            printf("%c", caractereActuel);
        } while (caractereActuel != EOF);
    }
}
/* Fin de la proc�dure */

/* D�but de la proc�dure */

void Modifier (struct Tcontact contact[100],int cpt)    /* La proc�dure re�oit cette fois deux variables, dont cpt qui caract�rise le nombre de contact(s) dans le r�pertoire */
{

    FILE* fichier = NULL;
    int i,rep,choix;

    modification:   /* Label qui permettra de revenir � cet endroit du programme si l'utilisateur le d�sire */
    printf("Quel contact voulez vous modifier ?\n");
    for (i=0;i<cpt;i++)
    {
        printf("Contact [%d] : %s %s\n",i+1,contact[i].Nom,contact[i].Prenom); /* Affichage des contacts, avec les deux informations essentielles les caract�risant : le nom et le pr�nom */
    }
    scanf("%d",&rep);
    while (rep > cpt || rep <=0)    /* Contr�le de saisie */
    {
        printf("Le contact saisi n'existe pas.\n");
        printf("Veuillez ressaisir le contact.\n");
        fflush(stdin);
        scanf("%d",&rep);
    }
    i = rep - 1; /* Par un soucis de claret� du point de vue de l'utilisateur, le premier contact "commence" � l'indice 1, c'est pourquoi il est n�cessaire de retirer 1 de i, pour que le contact corresponde vraiment a ce qui est contenue dans le tableau */
    champ:
    printf("Quel champ souhaitez vous modifier ?\n");
    printf("Choix 1 --> Nom\nChoix 2 --> Prenom\nChoix 3 --> Numero de la voie\nChoix 4 --> Type de la voie\nChoix 5 --> Nom de la voie\nChoix 6 --> CP\nChoix 7 --> Ville\nChoix 8 --> Email\nChoix 9 --> Tel\n");
    scanf("%d",&choix);
    while (choix != 0 && choix != 1 && choix != 2 && choix != 3 && choix !=4 && choix != 5 && choix != 6 && choix != 7 && choix != 8 && choix != 9)
    {
        printf("Choix incorrect. Veuillez ressaisir.\n");
        fflush(stdin);
        scanf("%d",&choix);
    }
    switch(choix){

                    case 1: printf("Quel est le nouveau nom ?\n");
                            fflush(stdin);
                            gets(contact[i].Nom);
                            printf("Voulez vous modifier un autre champ ? (0 pour non / 1 pour oui)\n");
                            fflush(stdin);
                            scanf("%d",&choix);
                            while (choix != 0 && choix != 1){
                            printf("Choix incorrect. Veuillez ressaisir.\n");
                            fflush(stdin);
                            scanf("%d",&choix);
                            }
                            if (choix == 1)
                                goto champ; /* L'instruction goto, permettant de revenir au label ici nomm� "champ" */
                            else
                            {
                                printf("Voulez vous modifier un autre contact ? (0 pour non / 1 pour oui)\n");
                                fflush(stdin);
                                scanf("%d",&choix);
                                while (choix != 0 && choix != 1){
                                printf("Choix incorrect. Veuillez ressaisir.\n");
                                fflush(stdin);
                                scanf("%d",&choix);
                                }
                                if (choix==1)
                                    goto modification; /* IDEM, mais redirige vers le label "modification */
                            }
                    break;

                    case 2: printf("Quel est le nouveau prenom ?\n");
                            fflush(stdin);
                            gets(contact[i].Prenom);
                            printf("Voulez vous modifier un autre champ ? (0 pour non / 1 pour oui)\n");
                            fflush(stdin);
                            scanf("%d",&choix);
                            while (choix != 0 && choix != 1){
                            printf("Choix incorrect. Veuillez ressaisir.\n");
                            fflush(stdin);
                            scanf("%d",&choix);
                            }
                            if (choix == 1)
                                goto champ;
                            else
                            {
                                printf("Voulez vous modifier un autre contact ? (0 pour non / 1 pour oui)\n");
                                fflush(stdin);
                                scanf("%d",&choix);
                                while (choix != 0 && choix != 1){
                                printf("Choix incorrect. Veuillez ressaisir.\n");
                                fflush(stdin);
                                scanf("%d",&choix);
                                }
                                if (choix==1)
                                    goto modification;
                            }
                    break;

                    case 3: printf("Quel est le nouveau numero de la voie ?\n");
                            fflush(stdin);
                            gets(contact[i].Numero_voie);
                            printf("Voulez vous modifier un autre champ ? (0 pour non / 1 pour oui)\n");
                            fflush(stdin);
                            scanf("%d",&choix);
                            while (choix != 0 && choix != 1){
                            printf("Choix incorrect. Veuillez ressaisir.\n");
                            fflush(stdin);
                            scanf("%d",&choix);
                            }
                            if (choix == 1)
                                goto champ;
                            else
                            {
                                printf("Voulez vous modifier un autre contact ? (0 pour non / 1 pour oui)\n");
                                fflush(stdin);
                                scanf("%d",&choix);
                                while (choix != 0 && choix != 1){
                                printf("Choix incorrect. Veuillez ressaisir.\n");
                                fflush(stdin);
                                scanf("%d",&choix);
                                }
                                if (choix==1)
                                    goto modification;
                            }
                    break;

                    case 4: printf("Quel est le nouveau type de la voie ?\n");
                            fflush(stdin);
                            gets(contact[i].Type_voie);
                            printf("Voulez vous modifier un autre champ ? (0 pour non / 1 pour oui)\n");
                            fflush(stdin);
                            scanf("%d",&choix);
                            while (choix != 0 && choix != 1){
                            printf("Choix incorrect. Veuillez ressaisir.\n");
                            fflush(stdin);
                            scanf("%d",&choix);
                            }
                            if (choix == 1)
                                goto champ;
                            else
                            {
                                printf("Voulez vous modifier un autre contact ? (0 pour non / 1 pour oui)\n");
                                fflush(stdin);
                                scanf("%d",&choix);
                                while (choix != 0 && choix != 1){
                                printf("Choix incorrect. Veuillez ressaisir.\n");
                                fflush(stdin);
                                scanf("%d",&choix);
                                }
                                if (choix==1)
                                    goto modification;
                            }
                    break;

                    case 5: printf("Quel est le nouveau nom de la voie ?\n");
                            fflush(stdin);
                            gets(contact[i].Nom_voie);
                            printf("Voulez vous modifier un autre champ ? (0 pour non / 1 pour oui)\n");
                            fflush(stdin);
                            scanf("%d",&choix);
                            while (choix != 0 && choix != 1){
                            printf("Choix incorrect. Veuillez ressaisir.\n");
                            fflush(stdin);
                            scanf("%d",&choix);
                            }
                            if (choix == 1)
                                goto champ;
                            else
                            {
                                printf("Voulez vous modifier un autre contact ? (0 pour non / 1 pour oui)\n");
                                fflush(stdin);
                                scanf("%d",&choix);
                                while (choix != 0 && choix != 1){
                                printf("Choix incorrect. Veuillez ressaisir.\n");
                                fflush(stdin);
                                scanf("%d",&choix);
                                }
                                if (choix==1)
                                    goto modification;
                            }
                    break;

                    case 6: printf("Quel est le nouveau CP ?\n");
                            fflush(stdin);
                            gets(contact[i].CP);
                            printf("Voulez vous modifier un autre champ ? (0 pour non / 1 pour oui)\n");
                            fflush(stdin);
                            scanf("%d",&choix);
                            while (choix != 0 && choix != 1){
                            printf("Choix incorrect. Veuillez ressaisir.\n");
                            fflush(stdin);
                            scanf("%d",&choix);
                            }
                            if (choix == 1)
                                goto champ;
                            else
                            {
                                printf("Voulez vous modifier un autre contact ? (0 pour non / 1 pour oui)\n");
                                fflush(stdin);
                                scanf("%d",&choix);
                                while (choix != 0 && choix != 1){
                                printf("Choix incorrect. Veuillez ressaisir.\n");
                                fflush(stdin);
                                scanf("%d",&choix);
                                }
                                if (choix==1)
                                    goto modification;
                            }
                    break;

                    case 7: printf("Quel est la nouvelle ville ?\n");
                            fflush(stdin);
                            gets(contact[i].Ville);
                            printf("Voulez vous modifier un autre champ ? (0 pour non / 1 pour oui)\n");
                            fflush(stdin);
                            scanf("%d",&choix);
                            while (choix != 0 && choix != 1){
                            printf("Choix incorrect. Veuillez ressaisir.\n");
                            fflush(stdin);
                            scanf("%d",&choix);
                            }
                            if (choix == 1)
                                goto champ;
                            else
                            {
                                printf("Voulez vous modifier un autre contact ? (0 pour non / 1 pour oui)\n");
                                fflush(stdin);
                                scanf("%d",&choix);
                                while (choix != 0 && choix != 1){
                                printf("Choix incorrect. Veuillez ressaisir.\n");
                                fflush(stdin);
                                scanf("%d",&choix);
                                }
                                if (choix==1)
                                    goto modification;
                            }
                    break;

                    case 8: printf("Quel est la nouvelle adresse email ?\n");
                            fflush(stdin);
                            gets(contact[i].Email);
                            printf("Voulez vous modifier un autre champ ? (0 pour non / 1 pour oui)\n");
                            fflush(stdin);
                            scanf("%d",&choix);
                            while (choix != 0 && choix != 1){
                            printf("Choix incorrect. Veuillez ressaisir.\n");
                            fflush(stdin);
                            scanf("%d",&choix);
                            }
                            if (choix == 1)
                                goto champ;
                            else
                            {
                                printf("Voulez vous modifier un autre contact ? (0 pour non / 1 pour oui)\n");
                                fflush(stdin);
                                scanf("%d",&choix);
                                while (choix != 0 && choix != 1){
                                printf("Choix incorrect. Veuillez ressaisir.\n");
                                fflush(stdin);
                                scanf("%d",&choix);
                                }
                                if (choix==1)
                                    goto modification;
                            }
                    break;

                    case 9: printf("Quel est le nouveau numero de telephone ?\n");
                            fflush(stdin);
                            gets(contact[i].Tel);
                            printf("Voulez vous modifier un autre champ ? (0 pour non / 1 pour oui)\n");
                            fflush(stdin);
                            scanf("%d",&choix);
                            while (choix != 0 && choix != 1){
                            printf("Choix incorrect. Veuillez ressaisir.\n");
                            fflush(stdin);
                            scanf("%d",&choix);
                            }
                            if (choix == 1)
                                goto champ;
                            else
                            {
                                printf("Voulez vous modifier un autre contact ? (0 pour non / 1 pour oui)\n");
                                fflush(stdin);
                                scanf("%d",&choix);
                                while (choix != 0 && choix != 1)
                                {
                                    printf("Choix incorrect. Veuillez ressaisir.\n");
                                    fflush(stdin);
                                    scanf("%d",&choix);
                                }
                                if (choix==1)
                                    goto modification;
                            }
                    break;
                }
    fichier = fopen("Contact.txt", "w"); /* On ouvre le fichier afin d'enregistrer en m�moire de masse le ou les changement(s) apport�s par l'utilisateur. */
    for (i=0;i<cpt;i++)
    {
        fprintf(fichier,"%s\n",contact[i].Nom); /* R�ecriture des diff�rentes informations dans le fichier "Contact" */
        fprintf(fichier,"%s\n",contact[i].Prenom);
        fprintf(fichier,"%s ",contact[i].Numero_voie);
        fprintf(fichier,"%s ",contact[i].Type_voie);
        fprintf(fichier,"%s\n",contact[i].Nom_voie);
        fprintf(fichier,"%s\n",contact[i].CP);
        fprintf(fichier,"%s\n",contact[i].Ville);
        fprintf(fichier,"%s\n",contact[i].Email);
        fprintf(fichier,"%s\n",contact[i].Tel);
        fprintf(fichier,"\n");
    }
    fclose(fichier);
}
/* Fin proc�dure */

void Supprimer (struct Tcontact contact[100],int cpt)
{

    FILE* fichier = NULL;
    int i,rep;

    suppression:
    printf("Quel contact souhaitez vous supprimer ?\n");
    for (i=0;i<cpt;i++)
    {
        printf("Contact [%d] : %s %s\n",i+1,contact[i].Nom,contact[i].Prenom); /*Affichage des contacts, caract�ris�s par leur nom et leur pr�nom.*/
    }
    scanf("%d",&rep);
    while (rep > cpt || rep <=0)
    {
        printf("Le contact saisi n'existe pas.\n");
        printf("Veuillez ressaisir le contact.\n");
        fflush(stdin);
        scanf("%d",&rep);
    }
    for(i=rep-1;i<cpt;i++)
    {
        strcpy(contact[i].Nom, contact[i+1].Nom); /* La fonction "strcpy" appartenant � la biblioth�que "string.h" permet de copier une cha�ne de caract�re. Ici, on d�place chaque indice i+1 � l'indice pr�c�dent i, afin d'�craser le r�sultat pr�c�dent et d'effacer le contact souhait� */
        strcpy(contact[i].Prenom, contact[i+1].Prenom);
        strcpy(contact[i].Numero_voie, contact[i+1].Numero_voie);
        strcpy(contact[i].Type_voie, contact[i+1].Type_voie);
        strcpy(contact[i].Nom_voie, contact[i+1].Nom_voie);
        strcpy(contact[i].CP, contact[i+1].CP);
        strcpy(contact[i].Ville, contact[i+1].Ville);
        strcpy(contact[i].Email, contact[i+1].Email);
        strcpy(contact[i].Tel, contact[i+1].Tel);
    }
    cpt = cpt - 1;
    fichier = fopen("Contact.txt", "w");
    for (i=0;i<cpt;i++)
    {
        fprintf(fichier,"%s\n",contact[i].Nom);
        fprintf(fichier,"%s\n",contact[i].Prenom);
        fprintf(fichier,"%s ",contact[i].Numero_voie);
        fprintf(fichier,"%s ",contact[i].Type_voie);
        fprintf(fichier,"%s\n",contact[i].Nom_voie);
        fprintf(fichier,"%s\n",contact[i].CP);
        fprintf(fichier,"%s\n",contact[i].Ville);
        fprintf(fichier,"%s\n",contact[i].Email);
        fprintf(fichier,"%s\n",contact[i].Tel);
        fprintf(fichier,"\n");
    }
        fclose(fichier);
    printf("Voulez vous supprimer un autre contact ? (1 pour oui / 0 pour non)\n");
    scanf("%d",&rep);
    while (rep != 0 && rep != 1){
        printf("Choix incorrect. Veuillez ressaisir.\n");
        fflush(stdin);
        scanf("%d",&rep);
}
    if (rep == 1)
        goto suppression;
}

// FONCTIONS ET PROCEDURES CONCERNANT L'AJOUT, LA MODIFICATION, LA SUPPRESSION ET L'AFFICHAGE DES CONTACTS DU CARNET
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// FONCTIONS ET PROCEDURES CONCERNANT LE CRYPTAGE ET LE DECRYPTAGE DES CONTACTS DU CARNET

int fonctionChoixDuCryptage (int premiereBorne, int deuxiemeBorne) //Cette fonction permet de determiner quelle m�thode de cryptage sera utilis�e
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

    return caractereEnCours;
}

char applicationCryptageCaractere (char caractereEnCours, int premiereBorne, int deuxiemeBorne) //Cette fonction contiendra l'ensemble des m�thodes de cryptage du prgramme
{
    int choixDuCryptage = fonctionChoixDuCryptage(premiereBorne, deuxiemeBorne);
    switch (choixDuCryptage)
    {
        case 1:
            ecritureFichierDecryptage(choixDuCryptage);
            caractereEnCours = cryptageCesar(caractereEnCours);
            break;
        case 2:
            ecritureFichierDecryptage(choixDuCryptage);
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

char applicationDecryptageCaractere (char caractereEnCours, int methodeDeDecryptage) //Cette fonction contiendra l'ensemble des m�thodes de decryptage du programme
{
    int choixDuDecryptage = methodeDeDecryptage;
    switch (choixDuDecryptage)
    {
        case 1:
            caractereEnCours = decryptageCesar(caractereEnCours);
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

void ecritureFichierDecryptage (int choixDuCryptage) //cette proc�dure �crira dans le fichier decryptage.txt la cl� n�cessaire au d�cryptage des informations
{
    FILE* fichier2 = NULL;

    fichier2 = fopen("decryptage.txt", "a");

    if (fichier2 != NULL)
    {
        fprintf(fichier2,"%d",choixDuCryptage); // �criture du caract�re contenu dans choixDuCryptage
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

        caractereActuel = fgetc(fichier2);
        sprintf(temporaire,"%c",caractereActuel);
        methodeDeDecryptage = atoi(temporaire);
        fclose(fichier2);
    }

    return methodeDeDecryptage; //retourne le num�ro de la m�thode de cryptage � utiliser pour le caract�re positionCaractereEnCours
}

void cryptageDuFichier (char caractereEnCours, int premiereBorne, int deuxiemeBorne) //Cette proc�dure servira � appeler l'ensemble des autres proc�dures/fonction n�cessaires au cryptage du fichier
{
    FILE* fichier = NULL;
    FILE* fichier2 = NULL;
    //int caractereActuel = 0;

    fichier = fopen("Contact.txt", "r");
    fichier2 = fopen("ContactCrypte.txt", "w");
    if (fichier != NULL)
    {
        do                               /* On cr�e une boucle afin de lire tous les caract�res un par un, jusqu'� ce que le r�sultat contenu soit End Of File */
        {
            caractereEnCours = fgetc(fichier);
            fputc(applicationCryptageCaractere(caractereEnCours, premiereBorne, deuxiemeBorne), fichier2);
        } while (caractereEnCours != EOF);
        fclose(fichier);
        fclose(fichier2);
        puts("FIN DU CRYPTAGE DU FICHIER !\n");
    }
}

void decryptageDuFichier (char caractereEnCours, long positionCaractereEnCours)
{
    FILE* fichier = NULL;
    FILE* fichier3 = NULL;
    int methodeDeDecryptage;

    fichier = fopen("ContactCrypte.txt", "r"); /* On ouvre le fichier en lecture seule */
    fichier3 = fopen("ContactDecrypte.txt", "w");
    if (fichier != NULL)
    {
        do
        {
            caractereEnCours = fgetc(fichier);
            methodeDeDecryptage = lectureFichierDecryptage(positionCaractereEnCours); //d�termine la m�thode de d�cryptage � utiliser pour d�crypter le caract�re caractereEnCours a la position positionCaractereEnCours
            positionCaractereEnCours += 1;
            //printf("%c", applicationDecryptageCaractere(caractereEnCours, methodeDeDecryptage));
            fputc(applicationDecryptageCaractere(caractereEnCours, methodeDeDecryptage), fichier3);
        } while (caractereEnCours != EOF);
    }
    fclose(fichier);
    fclose(fichier3);
    puts("FIN DU DECRYPTAGE DU FICHIER !");
}

void detruireCleDeDecryptage()
{
    remove("decryptage.txt");
}

int main ()
{
    int premiereBorne = 1; //On souhaite que chaque caract�re soit crypt� entre 1
    int deuxiemeBorne = 9; //Et 9 fois
    //int choix = NULL;
    long positionCaractereEnCours = 0;
    char caractereEnCours = ' ';
    srand(time(NULL)); //time() retourne le nombre de secondes �coul�es depuis le 1er janvier 1970

    int choix,rep,i,cpt;
    struct Tcontact contact[100];
    FILE* fichier = NULL;
    menu:
    i = 0;
    cpt = -1;
    fichier = fopen("Contact.txt", "r");
    if (fichier != NULL)
    {
        do  /* Cette boucle va permettre d'�crire le contenu du fichier "Contact.txt" en m�moire vive afin de pouvoir travailler dessus. */
        {
           fscanf(fichier,"%s",contact[i].Nom);
           fscanf(fichier,"%s",contact[i].Prenom);
           fscanf(fichier,"%s %s %s",contact[i].Numero_voie,contact[i].Type_voie,contact[i].Nom_voie);
           fscanf(fichier,"%s",contact[i].CP);
           fscanf(fichier,"%s",contact[i].Ville);
           fscanf(fichier,"%s",contact[i].Email);
           fscanf(fichier,"%s",contact[i].Tel);
           i = i + 1;
           cpt = cpt + 1;
        }
        while(!feof(fichier));
    }
    fclose(fichier);
    printf("Choisissez ce que vous voulez faire. \n");
    printf("\n");
    printf("Cas [1] : Ajout d'un nouveau contact \nCas [2] : Modification d'un contact existant \nCas [3] : Suppression d'un contact existant \nCas [4] : Affichage des contacts actuels \nCas [5] : Cryptage du fichier \nCas [6] : Decryptage du fichier \nCas [7] : Quitter le programme \n");
    fflush(stdin);
    scanf("%d",&choix);
    while (choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5 && choix != 6 && choix != 7)
        {
            printf("Ce choix n'existe pas. Veuillez le refaire.\n");
            fflush(stdin);
            scanf("%d",&choix);
        }
    switch(choix)
    {
        case 1 :    printf("--> Ajout d'un nouveau contact <-- \n");
                    Ajout(contact,cpt);
                    printf("Voulez vous retourner dans le menu ? (1 pour y retourner / 0 pour quitter)\n");
                    scanf("%d",&rep);
                    while (rep != 0 && rep != 1)
                    {
                        printf("Choix incorrect. Veuillez ressaisir.\n");
                        fflush(stdin);
                        scanf("%d",&rep);
                    }
                    if (rep == 1)
                        goto menu;
                    else
                    return 0;
        break;

        case 2 :    printf("--> Modification d'un contact existant <-- \n");
                    Modifier(contact,cpt);
                    printf("Voulez vous retourner dans le menu ? (1 pour y retourner / 0 pour quitter)\n");
                    scanf("%d",&rep);
                    while (rep != 0 && rep != 1)
                    {
                        printf("Choix incorrect. Veuillez ressaisir.\n");
                        fflush(stdin);
                        scanf("%d",&rep);
                    }
                    if (rep == 1)
                        goto menu;
                    else
                    return 0;
        break;

        case 3 :    printf("--> Suppression d'un contact existant <-- \n");
                    Supprimer(contact,cpt);
                    printf("Voulez vous retourner dans le menu ? (1 pour y retourner / 0 pour quitter)\n");
                    scanf("%d",&rep);
                    while (rep != 0 && rep != 1)
                    {
                        printf("Choix incorrect. Veuillez ressaisir.\n");
                        fflush(stdin);
                        scanf("%d",&rep);
                    }
                    if (rep == 1)
                        goto menu;
                    else
                    return 0;
        break;

        case 4 :    printf("--> Affichage des contacts actuels <--\n");
                    printf("\n");
                    Affichage(contact);
                    printf("\n");
                    printf("Voulez vous retourner dans le menu ? (1 pour y retourner / 0 pour quitter)\n");
                    scanf("%d",&rep);
                    while (rep != 0 && rep != 1)
                    {
                        printf("Choix incorrect. Veuillez ressaisir.\n");
                        fflush(stdin);
                        scanf("%d",&rep);
                    }
                    if (rep == 1)
                        goto menu;
                    else
                    return 0;
        break;

        case 5 :    puts("Le fichier va maintenant etre crypte...");
                    detruireCleDeDecryptage();
                    cryptageDuFichier(caractereEnCours, premiereBorne, deuxiemeBorne);
                    printf("Voulez vous retourner dans le menu ? (1 pour y retourner / 0 pour quitter)\n");
                    scanf("%d",&rep);
                    while (rep != 0 && rep != 1)
                    {
                        printf("Choix incorrect. Veuillez ressaisir.\n");
                        fflush(stdin);
                        scanf("%d",&rep);
                    }
                    if (rep == 1)
                        goto menu;
                    else
                    return 0;
        break;

        case 6 :    puts("Le fichier va maintenant etre decrypte...");
                    decryptageDuFichier(caractereEnCours, positionCaractereEnCours);
                    printf("Voulez vous retourner dans le menu ? (1 pour y retourner / 0 pour quitter)\n");
                    scanf("%d",&rep);
                    while (rep != 0 && rep != 1)
                    {
                        printf("Choix incorrect. Veuillez ressaisir.\n");
                        fflush(stdin);
                        scanf("%d",&rep);
                    }
                    if (rep == 1)
                        goto menu;
                    else
                    return 0;
        break;

        case 7 :    printf("--> Le programme va maintenant etre ferme. <--\n");
                    return 0;
        break;

    }
    return 0;
}
