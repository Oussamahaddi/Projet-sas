#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>



typedef struct {
    int code_Product;
    char nom[50];
    int quantite_Produit;
    int prix;
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
    printf("\n--- 1 --- Ajouter un nouveau produit. \n");
    printf("\n--- 2 --- Ajouter plusieur nouveaux produits. \n");
    printf("\n--- 3 --- Lister tous les produits. \n");
    printf("\n--- 4 --- Acheter un produit. \n");
    printf("\n--- 5 --- Recherche un produit. \n");
    printf("\n--- 6 --- Quitter le programme. \n");
}

void print_product(Produit P[], int i) {
    printf("\nCode de produit : %d \n", P[i].code_Product);
    printf("Nom de produit : %s \n", &P[i].nom);
    printf("Quantite de produit : %d \n", P[i].quantite_Produit);
    printf("Prix de produit : %d \n", P[i].prix);
}

int n = 0;

void ajouter_un_product(Produit P[]) {
    printf("Code de produit : ");
    scanf("%d", &P[n].code_Product);
    printf("Nom de produit : ");
    scanf("%s", &P[n].nom);
    printf("Quantite de produit : ");
    scanf("%d", &P[n].quantite_Produit);
    printf("Prix de produit : ");
    scanf("%d", &P[n].prix);
    n++;
}

void ajouter_plusieur_product(Produit P[], int nombre_produit) {
    printf("* Combien des produits tu veux ajouter : ");
    scanf("%d", &nombre_produit);
    for (int i = n; i < n + nombre_produit; i++) {
        printf("Produit N %d \n", i + 1);
        printf("Code de produit : ");
        scanf("%d", &P[i].code_Product);
        printf("Nom de produit : ");
        scanf("%s", &P[i].nom);
        printf("Quantite de produit : ");
        scanf("%d", &P[i].quantite_Produit);
        printf("Prix de produit : ");
        scanf("%d", &P[i].prix);
    }
    n+=nombre_produit;
}

void lister_Produits() {
    // nom,prix,prix ttc    || prix ttc = prix * 15%
    // ordrer alpha
    // ordre decroissant de prix
}

void acheter_Produit() {

}

void recherche_produit(int code, int quantite, Produit P[]) {

    int methode_de_Recherche;
    int i;
    int nombre_produit;

    printf("\n* Recherche par : \n\n");
    printf("- 1 - Code de Produit. \n\n");
    printf("- 2 - Quantite de Produit. \n");
    printf("\nChoisir : ");
    scanf("%d", &methode_de_Recherche);

    do {
        switch (methode_de_Recherche) {
            case 1 :
                printf("\n* Entrer le code de produit que tu veux afficher : ");
                scanf("%d", &code);
                for (i = 0; i < n + nombre_produit; i++) {
                    if (code == P[i].code_Product) {
                        print_product(P, i);
                        break;
                    }
                }
                break;
            case 2 :
                printf("\n* Entrer la Quantite de produit : ");
                scanf("%d", &quantite);
                for (i = 0; i < n + nombre_produit; i++) {
                    if (quantite == &P[i].quantite_Produit) {
                        print_product(P, i);
                        break;
                    }
                }
                break;
            default :
                printf("Y a pas ce choix dans list \n");
                break;
        }
    } while (methode_de_Recherche > 0 || methode_de_Recherche < 3);
}

int main() {

    design();

    int operation;
    int quantite;
    int nombre_produit;
    int product_Rechercher;
    int code;
    int quitter;

    Produit P[100];

    do {
        list_de_choix();

        printf("\n* Choisir l'operation que tu a besoin : ");
        scanf("%d", &operation);

        switch (operation) {
            case 1 : 
                ajouter_un_product(P);
                break;
            case 2 :
                ajouter_plusieur_product(P, nombre_produit);
                break;
            case 3 :
                lister_Produits();
                break;
            case 4 :
                acheter_Produit();
                break;
            case 5 :
                recherche_produit(code, quantite, P);
                break;
        }

        printf("Tu veux quitter le programme ? \n- 1 - Yes \n- 2 - No\n");
        printf("Choisir : ");
        scanf("%d", &quitter);

        //system("cls");

    } while ((operation > 0 || operation < 5) && (quitter != 1));



    return 0;
}












