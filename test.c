// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <string.h>
// #include <ctype.h>

// int count = -1;
// typedef struct{
    
//     char title[100];
//     int noi;
//     char ingre[30][20];
// }Menu;
// void printAction()
// {
//     printf("1. Add New Menu\n");
//     printf("2. Edit Menu\n");
//     printf("3. Delete Menu\n");
//     printf("4. Pick Menu\n");
//     printf("5. Exit\n");
// }

// int main()
// {
//     int A;
//     Menu menu[100];
//     while(1){
//         printAction();
//         scanf("%d", &A);
//         getchar();
//         if(A == 5) break;
//         if(A == 1){
//             printf("Adding Menu :\n\nEnter the menu title : ");
//             fgets(menu[++count].title,100,stdin);
//             menu[count].title[strcspn(menu[count].title,"\n")] = '\0';
            
//             for(int i = 0;menu[count].title[i];i++)
//             {
//                 menu[count].title[i] = toupper((unsigned char)menu[count].title[i]);
//             }
//             printf("Enter the number of ingredients : ");
//             scanf("%d", &menu[count].noi);
//             getchar();
//             for(int i = 0;i < menu[count].noi;i++)
//             {
//                 printf("Enter ingredients : ");
//                 fgets(menu->ingre[i],20,stdin);
//                 for(int j = 0;menu->ingre[i][j];j++)
//             {
//                 menu->ingre[i][j] = toupper((unsigned char)menu->ingre[i][j]);
//             }
//                 // menu->ingre[i][strcspn(menu->ingre[i],"\n")] = '\0';
               
//             }
//             printf("\n\n%s\n", menu[count].title);
//             for(int i = 0;i< menu[count].noi;i++)
//             {
//                 printf("%d. %s",i + 1, menu->ingre[i]);
               
//             }
//             printf("Menu Added.\n");
//             printf("\n----------------------------\n\n");
//         }
//         if(A == 4){
//             int r = rand() % count + 1;
//             printf("%d", r);
//             printf("%s\n", menu[r].title);
//         }

//     }
    
    
    



//     return 0;
// }