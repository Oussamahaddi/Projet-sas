#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <windows.h>


typedef struct {
    int code_Product;
    char nom[50];
    int quantite_Produit;
    float prix;
}Produit; 

void design(){
    printf("*****************************************************************\n");
    printf("*     ****      *                                *     ****     *\n");
    printf("*     ****      *                                *     ****     *\n");
    printf("*****************     GESTION  DE  PHARMACIE     ****************\n");
    printf("*****************     GESTION  DE  PHARMACIE     ****************\n");
    printf("*     ****      *                                *     ****     *\n");
    printf("*     ****      *                                *     ****     *\n");
    printf("*****************************************************************\n");
}

void list_de_choix() {
    printf("*--- 1 --- Ajouter un nouveau produit.                          *\n");
    printf("*                                                               *\n");
    printf("*--- 2 --- Ajouter plusieur nouveaux produits.                  *\n");
    printf("*                                                               *\n");
    printf("*--- 3 --- Lister tous les produits.                            *\n");
    printf("*                                                               *\n");
    printf("*--- 4 --- Acheter un produit.                                  *\n");
    printf("*                                                               *\n");
    printf("*--- 5 --- Recherche un produit.                                *\n");
    printf("*                                                               *\n");
    printf("*--- 6 --- Quitter le programme.                                *\n");
    printf("*****************************************************************\n\n");
}

int i, j;
int n = 0;
int quantite;
int code;
Produit P[100];

void affiche_product() {
    printf("\nCode de produit : %d \n", P[i].code_Product);
    printf("Nom de produit : %s \n", &P[i].nom);
    printf("Quantite de produit : %d \n", P[i].quantite_Produit);
    printf("Prix de produit : %.2f \n", P[i].prix);
}


void ajouter_un_product() {
    printf("- Code de produit :");
    scanf("%d", &P[n].code_Product);
    printf("- Nom de produit : ");
    scanf("%s", &P[n].nom);
    printf("- Quantite de produit : ");
    scanf("%d", &P[n].quantite_Produit);
    printf("- Prix de produit : ");
    scanf("%f", &P[n].prix);
    printf("--> Le produit %s a ete ajouter \n", P[n].nom);
    n++;
}

void ajouter_plusieur_product() {
    int nombre_produit;

    printf("* Combien des produits tu veux ajouter : ");
    scanf("%d", &nombre_produit);
    for (int i = n; i < n + nombre_produit; i++) {
        printf("----- Produit N %d -----\n", i + 1);
        printf("- Code de produit : ");
        scanf("%d", &P[i].code_Product);
        printf("- Nom de produit : ");
        scanf("%s", &P[i].nom);
        printf("- Quantite de produit : ");
        scanf("%d", &P[i].quantite_Produit);
        printf("- Prix de produit : ");
        scanf("%f", &P[i].prix);
        printf("--> Le produit %s a ete ajouter \n", P[n].nom);
    }
    n+=nombre_produit;
}

void lister_Produits() {
    int lister;
    Produit swap;

    printf("\n* Choisir la methode de triage \n");
    printf("- 1 - Lister les produit en Ordre Alphabetique croissant \n");
    printf("- 2 - Lister les produit en Ordre Decroissant de prix \n");
    printf("* Choisir : ");
    scanf("%d", &lister);
    
    switch (lister) {
        float ttc;
        case 1 :
            for (i = 1; i < n; i++) {
                if (strcmp(P[j - 1].nom,P[j].nom) < 0) {
                    swap = P[j];
                    P[j] = P[j - 1];
                    P[j - 1] = swap;
                    j--;
                } else if (strcmp(P[j - 1].nom,P[j].nom) == 0) {}
            }
            for (i = 0; i < n; i++) {
                printf("Nom de produit : %s \n", P[i].nom);
                printf("Prix de produit : %d \n", P[i].prix);
                P[i].prix = P[i].prix + 0.15;
                printf("Prix TTC de produit : %.2f \n", P[i].prix);
                printf("\n");
            }
            break;
        case 2 :
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
                
                printf("Nom de produit : %s \n", P[i].nom);
                printf("Prix de produit : %d \n", P[i].prix);
                P[i].prix = P[i].prix + 0.15;
                printf("Prix TTC de produit : %d \n", P[i].prix);
                printf("\n");
            }
            break;
    }
}

void acheter_Produit() {

}

void recherche_produit() {

    int methode_de_Recherche;

    printf("\n* Recherche par : \n\n");
    printf("- 1 - Code de Produit. \n\n");
    printf("- 2 - Quantite de Produit. \n\n");
    printf("* Choisir : ");
    scanf("%d", &methode_de_Recherche);

    do {
        switch (methode_de_Recherche) {
            case 1 :
                printf("\n* Entrer le code de produit que tu recherche : ");
                scanf("%d", &code);
                for (i = 0; i < n; i++) {
                    if (code == P[i].code_Product) {
                        affiche_product();
                        break;
                    }
                }
                break;
            case 2 :
                printf("\n* Entrer la Quantite de produit que tu recherche : ");
                scanf("%d", &quantite);
                for (i = 0; i < n; i++) {
                    if (quantite == P[i].quantite_Produit) {
                        affiche_product();
                        break;
                    }
                }
                break;
            default :
                printf("Y a pas ce choix dans list \n");
                break;
        }
system("cls");
    } while (methode_de_Recherche > 0 || methode_de_Recherche < 3);
}

int main() {

    int operation;
    int quitter;

    do {
        design();
        list_de_choix();

        printf("\n* Choisir l'operation que tu a besoin : ");
        scanf("%d", &operation);

        switch (operation) {
            case 1 : 
                ajouter_un_product();
                break;
            case 2 :
                ajouter_plusieur_product();
                break;
            case 3 :
                lister_Produits();
                break;
            case 4 :
                acheter_Produit();
                break;
            case 5 :
                recherche_produit(code, quantite);
                break;
        }

        printf("Tu veux quitter le programme ? \n- 1 - Yes \n- 2 - No\n");
        printf("Choisir : ");
        scanf("%d", &quitter);

        //system("cls");

    } while ((operation > 0 || operation < 5) && (quitter != 1));



    return 0;
}












