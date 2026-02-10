#ifndef SHOPPING_H
#define SHOPPING_H

typedef struct{
    char title[30];
    int num;
    char ingre[30][30];
}Menu;
Menu menu[100];
extern int count;
void printAction();
void printMenu(const Menu *menu);
Menu * addAction(Menu *menu,int *count);
void deleteAction(Menu *menu,int *count);
void showMenu(Menu *menu,int *count);
void pickMenu(Menu *menu,int *count);
Menu* readfile(const char *filename1,const char *filename2,int *count);
void saveNew(const char *filename1,const char *filename2,Menu *menu,int *count);
void saveDelete(const char *filename1,const char *filename2,Menu *menu,int *count);




#endif