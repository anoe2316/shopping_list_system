#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "shopping.h"

int count;

void printAction()
{
    printf("┌──────────────────────┐\n");
    printf("│      MENU SELECT     │\n");
    printf("├──────────────────────┤\n");   
    printf("| 1. Add New Menu.     |\n");
    printf("| 2. View All Menu.    |\n");
    printf("| 3. Today Menu        |\n");
    printf("| 4. Exit              |\n");
    printf("└──────────────────────┘\n");
    printf("Select > _  ");
}
int addAction(Menu **menu,int *count)
{
    Menu *temp = realloc(*menu,sizeof(Menu) * (*count + 1));
    if (temp == NULL) {
    printf("Memory allocation failed\n");
    return 0;
    }
    *menu = temp;
    Menu *m = &((*menu)[*count]);
    printf("Enter the menu title : ");
    fgets(m->title,30,stdin);
    m->title[strcspn(m->title,"\n")] = '\0';
    for(int i = 0;m->title[i];i++)
    {
        m->title[i] = toupper((unsigned char)m->title[i]);
    }
    printf("Enter the number of ingredients : ");
    if (scanf("%d", &m->num) != 1) {
    printf("Invalid input!\n");

    while (getchar() != '\n');  
    return 0;               
    }
    
    getchar();
    for(int i = 0;i < m->num;i++)
    {
        fgets(m->ingre[i],30,stdin);
        m->ingre[i][strcspn(m->ingre[i],"\n")] = '\0';
        for(int j = 0;m->ingre[i][j];j++)
        m->ingre[i][j] = toupper((unsigned char)m->ingre[i][j]);
    }
    *menu = temp;
    (*count)++;
    return 1;
}

int editAction(Menu *menu,int *count)
{
    int numm = 0,nume = 0;
    
    showMenu(menu,count);
    printf("0. Back\n");
    printf("Enter the menu number : ");
    scanf("%d", &numm);
    if(numm == 0) return 0;
    for(int i = 0;i < *count;i++)
    {
        if(i == numm - 1){
            printMenu(&menu[i]);
        }
    }
    printf("┌──────────────────────────┐\n");
    printf("│      MENU SELECT         │\n");
    printf("├──────────────────────────┤\n"); 
    printf("| 1. Edit Menu Title.      |\n");
    printf("| 2. Edit Ingredient Name. |\n");
    printf("| 3. Add New Ingredient.   |\n");
    printf("| 4. Delete Ingredient.    |\n");
    printf("| 5. Back                  |\n");            
    printf("└──────────────────────────┘\n");
    printf("Select > _  ");
    
    scanf("%d", &nume);
    getchar();
    switch(nume)
    {
        case 1: printf("Enter New Title : ");
                
                char new[30];
                for(int i = 0;i < *count;i++)
                {
                    if(i == (numm-1)){
                        fgets(new,30,stdin);
                        new[strcspn(new,"\n")] = '\0';
                        strcpy(menu[i].title,new);
                        for(int j = 0;menu[i].title[j];j++)
                            {
                                menu[i].title[j] = toupper((unsigned char)menu[i].title[j]);
                            }
                    }
                    
                }
                printf("\nDone Editing!\n\n");break;
        case 2: {   int numi = 0;
                for(int i = 0;i < *count;i++)
                    {
                        if(i == numm - 1){
                            printMenu(&menu[i]);
                            printf("Enter Ingredient number : ");
                            scanf("%d", &numi);
                            getchar();
                            printf("Enter New Ingredients Name : ");
                            fgets(new,30,stdin);
                            new[strcspn(new,"\n")] = '\0';
                            strcpy(menu[i].ingre[numi - 1],new);
                            for(int j = 0;menu[i].ingre[numi - 1][j];j++)
                            {
                                menu[i].ingre[numi - 1][j] = toupper((unsigned char)menu[i].ingre[numi - 1][j]);
                            }
                            }
                            
                    }
                    printf("\nDone Editing!\n\n");
                    }break;
        case 3: printf("Enter ingredient Name : ");
                
                for(int i = 0;i < *count;i++)
                {
                    if(i == (numm-1))
                    {
                    char *s = menu[i].ingre[menu[i].num];
                    
                    fgets(new,30,stdin);
                    new[strcspn(new,"\n")] = '\0';
                    strcpy(s,new);
                    menu[i].num++;
                    for(int j = 0;s[j];j++)
                            {
                                s[j] = toupper((unsigned char)s[j]);
                            }
                    }
                    
                }
                printf("\nDone Editing!\n\n");break;
        case 4: {int numi = 0;
                for(int i = 0;i < *count;i++)
                    {
                        if(i == numm - 1){
                            printMenu(&menu[i]);
                            printf("Enter Ingredient number : ");
                            scanf("%d", &numi);
                            for(int j = numi - 1;j < menu[i].num - 1;j++)
                            {
                                strcpy(menu[i].ingre[j],menu[i].ingre[j+1]);
                            }
                            menu[i].num--;
                            }
                            
                    }
                    printf("\nDone Editing!\n\n");
                    }break;

                           
        case 5: return 0;
    }
    return numm;
}
void deleteAction(Menu *menu,int *count)
{
    int denum = 0;
    showMenu(menu,count);
    printf("0. Back\n");
    printf("Choose :");
    scanf("%d", &denum);
    if(denum == 0) return;
    for(int i = denum - 1;i < (*count-1);i++)
    {
        menu[i] = menu[i+1];
    }
    (*count)--;
    printf("\nSuccessfully Deleted!\n\n");
    
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
int printAction2()
{
    int choice = 0;
    printf("\n");
    printf("┌──────────────────────┐\n");
    printf("│      MENU SELECT     │\n");
    printf("├──────────────────────┤\n");  
    printf("| 1. View Menu Detail. |\n");
    printf("| 2. Edit Menu.        |\n");
    printf("| 3. Delete Menu.      |\n");
    printf("| 4. Back.             |\n");
    printf("└──────────────────────┘\n");
    printf("Select > _  ");
    scanf("%d", &choice);
    return choice;
}
void showMenu(Menu *menu,int *count)
{
    printf("Registered Menu :\n\n");
    for(int i = 0;i < *count;i++){
        printf("%d. %s\n", i + 1,menu[i].title);
    }
    

}
void viewallMenu(Menu *menu,int *count)
{
    printf("Registered Menu :\n\n");
    for(int i = 0;i < *count;i++){
        printf("%d. %s\n", i + 1,menu[i].title);
    }
    while(1)
    {
        int choice = printAction2();
         switch(choice)
        {
        case 1: {   int u = 0;
                showMenu(menu,count);
                printf("0. Back\n");
                printf("Enter the menu number : ");
                scanf("%d", &u);
                if(u == 0) break;
                for(int i = 0;i < *count;i++)
                {
                    if(i == u - 1)
                    {
                        printMenu(&menu[i]);
                    }
                }
                printf("\n------------------------");
                }break;

        case 2: editAction(menu,count);
                saveEdit("shopping.txt","ing.txt",menu,count);
                break;
        case 3: deleteAction(menu,count);
                saveDelete("shopping.txt","ing.txt",menu,count);
                break;
        case 4: return ;
                
        }    
    }
    
   
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
    
    printf("------------------------\n\n");

}
void saveEdit(const char *filename1,const char *filename2,Menu *menu,int *count)
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
    
    printf("------------------------\n\n");

}


