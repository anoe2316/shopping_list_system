#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "shopping.h"

int count;

void printAction()
{
    printf("1. Add New Menu\n");
    printf("2. Edit Menu\n");
    printf("3. Delete Menu\n");
    printf("4. Today Menu\n");
    printf("5. Show All Menu\n");
    printf("6. Exit\n");
    printf("Enter your action : ");
}

Menu *addAction(Menu *menu,int *count)
{
    menu = realloc(menu,sizeof(Menu) * (*count+1));
    Menu *m = &menu[*count];
    printf("Enter the menu title : ");
    fgets(m->title,30,stdin);
    m->title[strcspn(m->title,"\n")] = '\0';
    for(int i = 0;m->title[i];i++)
    {
        m->title[i] = toupper((unsigned char)m->title[i]);
    }
    printf("Enter the number of ingredients : ");
    scanf("%d", &m->num);
    getchar();
    for(int i = 0;i < m->num;i++)
    {
        fgets(m->ingre[i],30,stdin);
        m->ingre[i][strcspn(m->ingre[i],"\n")] = '\0';
        for(int j = 0;j < m->ingre[i][j];j++)
        m->ingre[i][j] = toupper((unsigned char)m->ingre[i][j]);
    }
    (*count)++;
    return menu;
}
void deleteAction(Menu *menu,int *count)
{
    int denum = 0;
    showMenu(menu,count);
    printf("Enter the menu number :");
    scanf("%d", &denum);
    for(int i = denum - 1;i < (*count-1);i++)
    {
        menu[i] = menu[i+1];
    }
    (*count)--;
    
    return;
}

void printMenu(const Menu *menu)
{
    printf("\n\nTitle : %s\n", menu->title);
    
    for(int i = 0;i < menu->num;i++)
    {
        printf("%d. %s\n",i+1, menu->ingre[i]);
        
    }
}

void showMenu(Menu *menu,int *count)
{
    printf("Registered Menu :\n\n");
    for(int i = 0;i < *count;i++){
        printf("%d. %s\n", i + 1,menu[i].title);
    }
    printf("\n------------------------\n\n");
}
void pickMenu(Menu *menu,int *count)
{
    int r = rand() % (*count);
    printf("\n\nPicked : %s\n", menu[r].title);
    printf("Here your shopping list\n\n");
    for(int i = 0;i < menu[r].num;i++)
    {
        printf("%d. %s\n",i + 1,menu[r].ingre[i]);
    }
    printf("\n------------------------\n\n");
}


Menu* readfile(const char *filename1,const char *filename2,int *count)
{
    char line1[100];char line2[100];char *token; *count = 0;
    FILE *fp1 = fopen(filename1,"r");
    while (fgets(line1, sizeof(line1), fp1)) 
    {
        (*count)++;            
    }fclose(fp1);
    fp1 = fopen(filename1,"r");
    Menu *menu = malloc(sizeof(Menu)* (*count));
    for(int i = 0;i < *count;i++)
    {
        fgets(line1, sizeof(line1), fp1);
        line1[strcspn(line1,"\n")] = '\0';
        strcpy(menu[i].title,line1);
    }

    fclose(fp1);

    FILE *fp2 = fopen(filename2,"r");
    for(int i = 0;i < *count;i++)
    {
        fgets(line2,sizeof(line2),fp2);
        line2[strcspn(line2,"\n")] = '\0';
        token = strtok(line2,",");
        menu[i].num = atoi(token);

        for(int j = 0;j < menu[i].num;j++)
        {
            token = strtok(NULL,",");
            strcpy(menu[i].ingre[j],token);
        }
        
    }
    
    for(int i = 0;i< *count;i++)
    {
        printf("%s ", menu[i].title);
        printf("%d ", menu[i].num);
        for(int j = 0;j < menu[i].num;j++)
        {
            printf("%s ", menu[i].ingre[j]);
        }
        printf("\n");
    }
    return menu;

}
void saveNew(const char *filename1,const char *filename2,Menu *menu,int *count)
{
    FILE *fp1 = fopen(filename1,"w");
    for(int i = 0;i < *count;i++)
    {
        fprintf(fp1,"%s\n",menu[i].title);
    }
    fclose(fp1);
    FILE *fp2 = fopen(filename2,"w");
    for(int i = 0;i < *count;i++)
    {
        fprintf(fp2,"%d,",menu[i].num);
        for(int j = 0;j < menu[i].num;j++)
        {
            fprintf(fp2,"%s",menu[i].ingre[j]);
            if(j != menu[i].num - 1) fprintf(fp2,",");
        }
        fprintf(fp2,"\n");
    }
    printf("Menu successfully added.");
    printf("\n------------------------\n\n");

}
void saveDelete(const char *filename1,const char *filename2,Menu *menu,int *count)
{
    FILE *fp1 = fopen(filename1,"w");
    for(int i = 0;i < *count;i++)
    {
        fprintf(fp1,"%s\n",menu[i].title);
    }
    fclose(fp1);
    FILE *fp2 = fopen(filename2,"w");
    for(int i = 0;i < *count;i++)
    {
        fprintf(fp2,"%d,",menu[i].num);
        for(int j = 0;j < menu[i].num;j++)
        {
            fprintf(fp2,"%s",menu[i].ingre[j]);
            if(j != menu[i].num - 1) fprintf(fp2,",");
        }
        fprintf(fp2,"\n");
    }
    printf("\nSuccessfully Delete!\n\n");
    printf("\n------------------------\n\n");

}

