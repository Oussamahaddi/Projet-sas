#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>
//#include <windows.h>


typedef struct {            // declare un struct qui contiens les infos des produits
    int code_Product;
    char nom[50];
    int quantite_Produit;
    float prix;
    float TTC;
}Produit;

typedef struct {            //  cette struct pour stocker les produits vendu avec quantite et la date d'achat
    int code_produit_vendu;
    int quantite_vendu;
    float prix_total_vendu;
    int jour;
    int mois;
    int annee;
}les_Achats;

// declarer et initializer les variable qu'on utiliser plusieur fois on global pour eviter la redeclaration a chaque fois
int i, j;
int n = 0;
int quantite;
int code;
int PV = 0;
int sommeQuantite = 0;

Produit P[1000];           // stocker le struct dans un tableau
les_Achats state[100];

Produit swap;           // ce struct pour stocker le produit que en veux swaper (changer ca place);

void design(){
    printf("\t\t\t*****************************************************************\n");
    printf("\t\t\t*     ****      *                                *     ****     *\n");
    printf("\t\t\t*     ****      *                                *     ****     *\n");
    printf("\t\t\t*****************     GESTION  DE  PHARMACIE     ****************\n");
    printf("\t\t\t*     ****      *                                *     ****     *\n");
    printf("\t\t\t*     ****      *                                *     ****     *\n");
    printf("\t\t\t*****************************************************************\n");
    printf("\t\t\t*--- 1 --- Ajouter un nouveau produit.                          *\n");
    printf("\t\t\t*                                                               *\n");
    printf("\t\t\t*--- 2 --- Ajouter plusieur nouveaux produits.                  *\n");
    printf("\t\t\t*                                                               *\n");
    printf("\t\t\t*--- 3 --- Lister tous les produits.                            *\n");
    printf("\t\t\t*                                                               *\n");
    printf("\t\t\t*--- 4 --- Acheter un produit.                                  *\n");
    printf("\t\t\t*                                                               *\n");
    printf("\t\t\t*--- 5 --- Recherche un produit.                                *\n");
    printf("\t\t\t*                                                               *\n");
    printf("\t\t\t*--- 6 --- Etat du stock.                                       *\n");
    printf("\t\t\t*                                                               *\n");
    printf("\t\t\t*--- 7 --- Alimenter le stock.                                  *\n");
    printf("\t\t\t*                                                               *\n");
    printf("\t\t\t*--- 8 --- Supprimer un produit.                                *\n");
    printf("\t\t\t*                                                               *\n");
    printf("\t\t\t*--- 9 --- Statistique de vente.                                *\n");
    printf("\t\t\t*                                                               *\n");
    printf("\t\t\t*--- 10 --- Quitter le programme.                               *\n");
    printf("\t\t\t*****************************************************************\n\n");
}
void affiche_product() {    // cette fonction pour n a pas repeter ce code a chaque fois en appel just la fonction
    printf("------------------------------------------------ \n\n");
    printf("\nCode de produit : %d \n", P[i].code_Product);
    printf("Nom de produit : %s \n", P[i].nom);
    printf("Quantite de produit : %d \n", P[i].quantite_Produit);
    printf("Prix de produit : %.2f \n", P[i].prix);
    printf("----------------------------------------------- \n\n");
}
void ajouter_un_product() {     // declarer un fonction qui ajouter un produit a chaque fois qu'on en appel
    printf("-----------------------------------------------\n\n");
    printf("    - Code de produit : ");
    scanf("%d", &P[n].code_Product);
    printf("\n");
    printf("    - Nom de produit : ");
    scanf("%s", &P[n].nom);
    printf("\n");
    printf("    - Quantite de produit : ");
    scanf("%d", &P[n].quantite_Produit);
    printf("\n");
    printf("    - Prix de produit : ");
    scanf("%f", &P[n].prix);
    printf("\n");
    printf("\n--> Le produit [ %s ] a ete ajouter \n", P[n].nom);
    printf("-----------------------------------------------\n\n");
    n++;
}
void ajouter_plusieur_product() {   // declarer un fonction qui ajoute plusieur produits utilisant les boucles

    int nombre_produit;

    printf("\n* Combien des produits tu veux ajouter : ");
    scanf("%d", &nombre_produit);
    for (int i = n; i < n + nombre_produit; i++) {        // ici jai cree un for qui commence par n a  n+nombre_produit
        printf("-------------------------------------------\n\n");
        printf("    ----- Produit N %d -----\n", i + 1);
        printf("    - Code de produit : ");
        scanf("%d", &P[i].code_Product);
        printf("    - Nom de produit : ");
        scanf("%s", &P[i].nom);
        printf("    - Quantite de produit : ");
        scanf("%d", &P[i].quantite_Produit);
        printf("    - Prix de produit : ");
        scanf("%f", &P[i].prix);
        printf("\n--> Le produit [ %s ] a ete ajouter \n", P[i].nom);
    }
    n+=nombre_produit;
}
void trier_Croissant_Alphabitique() {   // trier par ordre croissant alphabitique utilisont tri par bulle
    for (i = 0; i < n - 1; i++) {  
        for (j = 1; j < n; j++) {
            if (strcmp(P[i].nom,P[j].nom) > 0) {
                swap = P[i];
                P[i] = P[j];
                P[j] = swap;
            }
        }
    }
    for (i = 0; i < n; i++) {
        P[i].TTC = P[i].prix + (P[i].prix * 15 / 100);
        printf("Nom de produit : %s \n", P[i].nom);
        printf("Prix de produit : %.2f \n", P[i].prix);
        printf("Prix TTC de produit : %.2f \n", P[i].TTC);
        printf("\n");
    }
}
void trier_Decroissant_Prix() {     // trier par ordre decroissant utilisont methode tri par insertion
    for (i = 1; i < n; i++) {       
        j = i;
        while (j > 0 && P[j - 1].prix < P[j].prix) {
            swap = P[j];
            P[j] = P[j - 1];
            P[j - 1] = swap;
            j--;
        }
    }
    for (i = 0; i < n; i++) {
        P[i].TTC = P[i].prix + (P[i].prix * 15 / 100);
        printf("Nom de produit : %s \n", P[i].nom);
        printf("Prix de produit : %.2f \n", P[i].prix);
        printf("Prix TTC de produit : %.2f \n", P[i].TTC);
        printf("\n");
    }
}
void lister_produits() {    // cette fonction pour afficher les produits apres le triage

    int lister;

    do {
        printf("\n* Choisir la methode de triage \n");
        printf("- 1 - Lister par Ordre Alphabetique croissant \n");
        printf("- 2 - Lister par Ordre decroissant des prix \n");
        printf("- 3 - Revien au Menu \n");
        printf("* Choisir : ");
        scanf("%d", &lister);
        printf("\n");

        switch (lister) {
            case 1 :
                trier_Croissant_Alphabitique();
                break;
            case 2 :
                trier_Decroissant_Prix();
                break;
            default :
                printf("\n--> Desoler ce choix introuvable !!! \n\n");
                break;
        } 
    } while (lister > 0 || lister < 3);
}
void acheter_produit() {

    double prix_total_ttc;       // stock le total des prix des produit vendu en ttc

    time_t temp = time(NULL);          
    struct tm date = *localtime(&temp);    // stocker function de temp qui donner la date d'aujourd'hui dans un struct appeler date

    printf("* Entrer le code de produit que tu veux acheter : ");
    scanf("%d", &code);
    printf("* Entrer la quantite que tu besoin : ");
    scanf("%d", &quantite);

    for (i = 0; i < n; i++) {
        if (code == P[i].code_Product) {
            if (quantite > P[i].quantite_Produit) {
                printf("\n* Desole il rest que %d quantite dans ce produit \n\n", P[i].quantite_Produit);
            } else if (P[i].quantite_Produit == 0) {
                printf("\n* Desoler la quantite de ce produit est epuise \n\n");
            } else if (quantite < 0) {
                printf("\n* Erreur 404 \n\n");
            } else {     // stocker les produis vendu avec les operation que fait et la date d'achat
                P[i].quantite_Produit = P[i].quantite_Produit - quantite;       //  decrementer la quandite de produit acheter
                prix_total_ttc = P[i].prix * quantite + ((P[i].prix * quantite) * 0.15);    // calcule total des prix des produit en ttc
                state[PV].prix_total_vendu = prix_total_ttc;                                
                state[PV].code_produit_vendu = P[i].code_Product;
                state[PV].quantite_vendu = quantite;
                state[PV].jour = date.tm_mday;
                state[PV].mois = date.tm_mon + 1;
                state[PV].annee = date.tm_year + 1900;
                printf("\n --> La Quantite de produit a ete bien mise a jour !!!! \n\n");
                PV++;
            }
            break;
        }
    }
}
void recherche_produit() {

    int methode_de_Recherche;

    printf("\n* Recherche par : \n\n");
    printf("- 1 - Code de Produit. \n\n");
    printf("- 2 - Quantite de Produit. \n\n");
    printf("- 3 - Revien au Menu. \n\n");
    printf("* Choisir : ");
    scanf("%d", &methode_de_Recherche);

    switch (methode_de_Recherche) {
        case 1 :
            printf("\n* Entrer le code de produit que tu recherche : ");
            scanf("%d", &code);
            for (i = 0; i < n; i++) {
                if (code == P[i].code_Product) {
                    affiche_product();
                    break;
                } else {
                    printf("\n* Desoler ya pas un produit avec ce code. \n");
                }
            }
            break;
        case 2 :
            printf("\n* Entrer la Quantite de produit que tu recherche : ");
            scanf("%d", &quantite);
            for (i = 0; i < n; i++) {
                if (quantite == P[i].quantite_Produit) 
                    affiche_product();
                else
                    printf("\n* Desoler ya pas un produit avec ce quantite. \n");
            }
            break;
        default :
            printf("* Il y a pas ce choix dans list \n");
            break;
    }
    printf("\n");
}
void etat_stock() {
    for (i = 0; i < n; i++) {
        if (P[i].quantite_Produit < 3) {
            printf("\n* Les produits qu'on quantite inferieur a 3 \n");
            affiche_product();
            printf("\n");
        } else {
            printf("\n* Il y a aucun produit inferier a 3 \n");
        }
    }
}
void alimenter_stock() {
    printf("* Entrer le code de produit : ");
    scanf("%d", &code);
    printf("* Entrer la quantite que tu veux ajouter : ");
    scanf("%d", &quantite);
    for (i = 0; i < n; i++) {
        if (code == P[i].code_Product) {
            P[i].quantite_Produit = P[i].quantite_Produit + quantite;
            printf("\n --> La Quantite de produit a ete bien mettre a jour !!!! \n\n");
            break;
        }
    }
    affiche_product();
}
void suppression_sroduit() {
    int index;
    int choix;

    printf("\n* Entrer le code de produit que tu veux supprimer : ");
    scanf("%d", &code);
    for (i = 0; i < n; i++) {
        if (code == P[i].code_Product) {
            index = i;
            break;
        }
    }
    printf("Est que tu es sur ? \n");
    printf("- 1 - Oui. \n");
    printf("- 2 - Non. \n");
    printf("* Choisir : ");
    scanf("%d", &choix);
    if (choix == 1) {
        for (i = index; i < n; i++) {
            swap = P[i];
            P[i] = P[i + 1];
            P[i + 1] = swap;
        }
        n--;
        printf("\n* L'operation succee !! \n\n");
    }
}
int affiche_total_prix() {

    double somme;

    time_t tempe = time(NULL);
    struct tm date = *localtime(&tempe);

    for (i = 0; i < PV; i++) {  
        if (state[i].jour == date.tm_mday && state[i].mois == date.tm_mon + 1 && state[i].annee == date.tm_year + 1900) {     
            somme += state[i].prix_total_vendu;
            sommeQuantite += state[i].quantite_vendu;
            printf("\n - Code Produit vendus : %d \n", state[i].code_produit_vendu);
            printf(" - Quantite vendus : %d \n", state[i].quantite_vendu);
            printf(" - Prix total vendus : %.2f \n", state[i].prix_total_vendu);
            printf(" - Vendu en : %d/%d/%d \n\n", state[i].jour, state[i].mois, state[i].annee);
            printf("---------------------------------------------------------------\n");
        }
    }

    return somme;

}
int affiche_moyenne_prix() {

    double moyenne;

    moyenne = affiche_total_prix() / sommeQuantite;

    return moyenne;
}
int affiche_max_prix() {

    double max_prix_vendu = state[0].prix_total_vendu;

    time_t tempe = time(NULL);
    struct tm date = *localtime(&tempe);

    for (i = 0; i < PV; i++) {  
            if (max_prix_vendu < state[i].prix_total_vendu && state[i].jour == date.tm_mday && state[i].mois == date.tm_mon + 1 && state[i].annee == date.tm_year + 1900)
                max_prix_vendu = state[i].prix_total_vendu;
    }

    return max_prix_vendu;

}
int affiche_min_prix() {

    time_t tempe = time(NULL);
    struct tm date = *localtime(&tempe);

    double min_prix_vendu = state[0].prix_total_vendu;
    
    for (i = 0; i < PV; i++) {
        if (min_prix_vendu > state[i].prix_total_vendu && state[i].jour == date.tm_mday && state[i].mois == date.tm_mon + 1 && state[i].annee == date.tm_year + 1900)
            min_prix_vendu = state[i].prix_total_vendu;
    }

    return min_prix_vendu;
    
}
void statistique_vente() {

    int chose;

    do {
        printf("\n- 1 - Afficher le total des prix des produits vendus en journee courante. \n\n");
        printf("- 2 - Afficher la moyenne des prix des produits vendus en journee courante. \n\n");
        printf("- 3 - Afficher le max des prix des produits vendus en journee courante. \n\n");
        printf("- 4 - Afficher le min des prix des produits vendus en journee courante. \n\n");
        printf("- 0 - Revien au Menu. \n\n");
        printf("* Choisir : ");
        scanf("%d", &chose);

        switch (chose) {
            case 1 :            
                printf("--> Total des prix des produits vendus est : %.2d (en TTC).\n\n", affiche_total_prix());
                break;
            case 2 :
                printf("\n* La moyenne des prix des produits vendus est : %.2d (en TTC). \n\n", affiche_moyenne_prix());
                break;
            case 3 :
                printf("--> Le Max des prix des produits vendu aujourd'hui : %.2d \n\n", affiche_max_prix());
                break;
            case 4 :
                printf("--> Le Min des prix des produits vendu aujourd'hui : %.2d \n\n", affiche_min_prix());
                break;
            default :
                printf("* Desole ya pas ce choix dans la liste \n\n.");
        }
    }while (chose != 0);
}

int main() {

    int operation;

    do {
        design();

        do {
            printf("\n* Choisir l'operation que tu a besoin : ");
            scanf("%d", &operation);
            if (operation == 10) {
                goto fin;
            }
        } while (operation < 0 || operation > 10);

        switch (operation) {
            case 1 : 
                ajouter_un_product();
                break;
            case 2 :
                ajouter_plusieur_product();
                break;
            case 3 :
                lister_produits();
                break;
            case 4 :
                acheter_produit();
                break;
            case 5 :
                recherche_produit();
                break;
            case 6 :
                etat_stock();
                break;
            case 7 :
                alimenter_stock();
                break;
            case 8 :
                suppression_sroduit();
                break;
            case 9 :
                statistique_vente();
                break;
            default :
                printf("\n* Desoler ce choix ya pas dans la list \n\n");
                break;
        }

    //system("cls");

    } while (operation != 10);

    fin :
        printf("\n\nMerciiiiii  :)\n\n\n");

    return 0;
}
