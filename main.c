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
        if (scanf("%d", &A) != 1)
    {
        printf("Invalid input! Please enter a number.\n");
        while (getchar() != '\n');  
        continue;
    }

    getchar();  

        switch(A)
        {
            case 1: {
                    if(addAction(&menu,&count)){
                        printMenu(&menu[count-1]);
                        saveNew("shopping.txt","ing.txt",menu,&count);
                    }
                    
                    break;}  
            
            case 2: viewallMenu(menu,&count);break;
            case 3: pickMenu(menu,&count);break;


            case 4: return 0;
            default: printf("'Invalid Input'\n");
                    
        }
    }
    
    


    return 0;
}