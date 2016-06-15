
char cryptageCesar (char caractereEnCours)
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

char decryptageCesar (char caractereEnCours) {
    /* Si le caractere est une minuscule */
    if ('a' <= caractereEnCours && caractereEnCours <= 'z')
        caractereEnCours = 'z' + ((caractereEnCours - 'z') - 13) % 26;
    else
        /* Si le caractere est une majuscule */
    if ('A' <= caractereEnCours && caractereEnCours <= 'Z')
        caractereEnCours = 'Z' + ((caractereEnCours - 'Z') - 13) % 26;
    else
        /* Si le caractere est un chiffre */
    if ('0' <= caractereEnCours && caractereEnCours <= '9')
        caractereEnCours = '0' + ((caractereEnCours - '0') - 13) % 10;
}