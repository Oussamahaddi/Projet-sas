#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>


typedef struct {
    int code_Product;
    char nom[50];
    int quantite_Produit;
    float prix;
    float TTC;
}Produit; 

void design(){
    printf("\t\t\t*****************************************************************\n");
    printf("\t\t\t*     ****      *                                *     ****     *\n");
    printf("\t\t\t*     ****      *                                *     ****     *\n");
    printf("\t\t\t*****************     GESTION  DE  PHARMACIE     ****************\n");
    printf("\t\t\t*     ****      *                                *     ****     *\n");
    printf("\t\t\t*     ****      *                                *     ****     *\n");
    printf("\t\t\t*****************************************************************\n");
}

void list_de_choix() {
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
    printf("\t\t\t*--- 10 --- Quitter le programme.                               *\n");
    printf("\t\t\t*****************************************************************\n\n");
}

int i, j;
int n = 0;
int quantite;
int code;
Produit P[1000];

Produit swap;

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
    printf("--> Le produit %s a ete ajouter \n\n", P[n].nom);
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
        // P[i].TTC = P[i].prix + 0.15;
        printf("--> Le produit %s a ete ajouter \n\n", P[n].nom);
    }
    n+=nombre_produit;
}

void trier_Croissant_Alphabitique() {
    for (i = 0; i < n - 1; i++) {   // trier par ordre croissant alphabitique utilisont tri par insertion
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
void trier_Decroissant_Prix() {
    for (i = 1; i < n; i++) {       // trier par ordre decroissant utilisont methode tri par insertion
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

void lister_produits() {
    int lister;
    int revien;
    Produit swap;

    do {
        printf("\n* Choisir la methode de triage \n");
        printf("- 1 - Lister par Ordre Alphabetique croissant \n");
        printf("- 2 - Lister par Ordre Decroissant de prix \n");
        printf("* Choisir : ");
        scanf("%d", &lister);
        printf("\n");

        switch (lister) {
            case 1 :
                trier_Croissant_Alphabitique(swap);
                break;
            case 2 :
                trier_Decroissant_Prix(swap);
                break;
            default :
                printf("* Merci !!! \n");
                break;
        } 
        printf("* Revien au Menu ? (Y/N) \n");
        printf("- 1 - Yes.\n");
        printf("- 2 - Non.\n");
        printf("* Choisir : ");
        scanf("%d", &revien);
    } while (revien != 1);
}

void acheter_produit() {
    printf("* Entrer le code de produit que tu veux acheter : ");
    scanf("%d", &code);
    printf("* Entrer la quantite que tu besoin : ");
    scanf("%d", &quantite);
    for (i = 0; i < n; i++) {
        if (code == P[i].code_Product) {
            if (quantite > P[i].quantite_Produit) {
                printf("* Desole il rest que %d sur ce produit \n", P[i].quantite_Produit);
            } else if (P[i].quantite_Produit == 0) {
                printf("* Sorry the quantite of this produit est epuise \n");
            } else {
                P[i].quantite_Produit = P[i].quantite_Produit - quantite;
                printf("\n --> La Quantite de produit a ete bien mise a jour !!!! \n\n");
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
                }
            }
            break;
        case 2 :
            printf("\n* Entrer la Quantite de produit que tu recherche : ");
            scanf("%d", &quantite);
            for (i = 0; i < n; i++) {
                if (quantite == P[i].quantite_Produit) 
                    affiche_product();
            }
            break;
        default :
            printf("* Il y a pas ce choix dans list \n");
            break;
    }
    printf("\n");
}

void etat_stock() {
    printf("* Les produits qu'on quantite inferieur a 3 \n");
    for (i = 0; i < n; i++) {
        if (P[i].quantite_Produit < 3) {
            affiche_product();
            printf("\n");
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
            default :
                printf("\n* Desoler ce choix ya pas dans la list \n\n");
                break;
        }

        printf("* Tu veux quitter le programme ? \n- 1 - Yes \n- 2 - No\n");
        printf("* Choisir : ");
        scanf("%d", &quitter);

    //system("cls");

    } while (quitter != 1);



    return 0;
}
