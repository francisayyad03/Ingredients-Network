#include <stdio.h>
#include "ingredient_graph.c"
#define MAX_STR_LEN 1024

#define SHRIMP ingredients[0]
#define HORSERADISH ingredients[1]
#define TURKEY ingredients[2]
#define SOYMILK ingredients[3]
#define TJUICE ingredients[4]
#define BREADCRUMBS ingredients[5]
#define ARTICHOKE ingredients[6]
#define CHEESE ingredients[7]
#define SEEDS ingredients[8]
#define QUINOA ingredients[9]


#ifdef ALL
    #define RELATED
    #define RELATEDK
    #define RELATEDRESTR
    #define SUB
#endif

intNode* head = NULL;
char recipe[10][MAX_STR_LEN] = {
"medium shrimp",
"prepared horseradish",
"turkey",
"soymilk",
"tomato juice",
"fresh breadcrumbs",
"",
"",
"",
""
};


void printArr (char p[10][MAX_STR_LEN]) {
    for (int i = 0; i < 10; i++) {
        if (strlen(recipe[i]) > 0) {
            printf("%s\n", p[i]);
        }
    }
}

void testRelated () {
    printf ("\n\n\n\n********** RELATED INREDIENTS**********\n");
    for (int i = 0; i != 10; i++) {
        printf("\n\n-- Related Ingredients for %s --\n", ingredients[i]);
        related_ingredients(ingredients[i]);
    }

    printf("\n\n\n-- Invalid Name --\n");
    char inv[MAX_STR_LEN] = "god";
    related_ingredients(inv);
}
void testRelatedK () {
    head = NULL;

    printf("\n\n\n\n********** RELATED K**********\n");
    printf("he said k was bigger than 0 so if it doesn't work it should be fine\n");
    for (int k = 0; k != 5; k++) {
        printf ("\n** k = %d **\n", k);

        for (int i = 0; i != 10; i++) {
            printf("\n -- Related k for %s --\n", ingredients[i]);
            head = related_k_dist(head, ingredients[i], k, 0);
            print_ingredients(head);
            head = deleteList(head);
        }
    }

    printf("\n\n\n-- Invalid Name --\n");
    char inv[MAX_STR_LEN] = "do";
    head = related_k_dist(head, inv, 1, 0);
    print_ingredients(head);
    head = deleteList(head);
}
void testRelatedRestr () {
    head = NULL;
    printf("\n\n\n\n********** RELATED w/ restrictions**********\n");

    for (int k = 0; k != 3; k++) {
        for (int k_avoid = 0; k_avoid != 3; k_avoid++) {
            printf("\n\n-- source = quinoa, avoid = tomato juice, k = %d, k_avoid = %d --\n", k, k_avoid);
            head = related_with_restrictions(QUINOA, TJUICE, k, k_avoid);
            print_ingredients(head);
            head = deleteList(head);
        }
    }

    printf("\n\n\n-- avoid == source k == k_avoid --\n");
    head = related_with_restrictions(QUINOA, QUINOA, 1, 1);
    print_ingredients(head);
    head = deleteList(head);

    printf("\n\n\n-- avoid == source k != k_avoid--\n");
    head = related_with_restrictions(QUINOA, QUINOA, 2, 1);
    print_ingredients(head);
    head = deleteList(head);

{
    printf("\n\n\n-- Invalid avoid --\n");
    char inv[MAX_STR_LEN] = "I";
    head = related_with_restrictions(QUINOA, inv, 2, 1);
    print_ingredients(head);
    head = deleteList(head);
}

    printf("\n\n\n-- Invalid source --\n");
    char inv[MAX_STR_LEN] = "love";
    head = related_with_restrictions(inv, QUINOA, 2, 1);
    print_ingredients(head);
    head = deleteList(head);
}
void testSub () {
    printf("\n\n\n\n********** Sub **********");
    for (int i = 0; i != 10; i++) {
        printf("\n\n-- sub %s --\n", ingredients[i]);
        substitute_ingredient(recipe, ingredients[i]);
        printArr(recipe);
    }

    printf("\n-- Invalid Name --\n");
    char inv[MAX_STR_LEN] = "Suisex";
    substitute_ingredient(recipe, inv);
    printArr(recipe);
}

int main () {
    printf("-- Available Ingredients --\n");
    load_ingredients();

    #ifdef RELATED
        testRelated();
    #endif

    #ifdef RELATEDK
        testRelatedK();
    #endif

    #ifdef RELATEDRESTR
        testRelatedRestr();
    #endif

    #ifdef SUB
        testSub();
    #endif
}