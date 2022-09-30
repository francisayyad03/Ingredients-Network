
//
//  A3_test.c
//  
//
//  Created by Elena Manneh on 2022-04-06.
//

#include<stdio.h>
#include<stdlib.h>
#include"ingredient_graph.c"

intNode *head=NULL;
char recipe[10][MAX_STR_LEN]={"fresh breadcrumbs",
              "artichoke hearts",
              "quinoa",
              "",
              "",
              "",
              "",
              "",
              "",
              ""};

intNode *newintNode()
{
    intNode *new_node=NULL;
    new_node=(intNode *)calloc(1, sizeof(intNode));

    new_node->x = 10;
    new_node->next = NULL;
    
    return new_node;
}

int main() {
    intNode *head=NULL;
    head=newintNode();
    insertInt(head, 1);
    insertInt(head, 2);
    load_ingredients();
    print_ingredients(head);
    
    return 0;
}