#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "shopping.h"


int main()
{
    Menu *menu = NULL;
    menu = readfile("shopping.txt","ing.txt",&count);
    srand(time(NULL));
    
    while(1){
        int A;
        printAction();
        scanf("%d", &A);
        getchar();
        switch(A)
        {
            case 1: menu = addAction(menu,&count);
                    printMenu(&menu[count-1]);
                    saveNew("shopping.txt","ing.txt",menu,&count);
                    break;
            case 3: deleteAction(menu,&count);
                    saveDelete("shopping.txt","ing.txt",menu,&count);break;
            case 4: pickMenu(menu,&count);break;
            case 5: showMenu(menu,&count);break;


            case 6: return 0;
                    
        }
    }
    
    


    return 0;
}