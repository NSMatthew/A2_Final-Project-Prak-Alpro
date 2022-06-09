#include "helpers.h"

int main(void)
{
    while(menu());

    return 0;
}

int menu(void)
{
    int opt;
    system("cls");
    printf("1. Add order\n");
    printf("2. See order\n");
    printf("3. Remove order\n");
    printf("4. Exit\n");

    do
    {
        printf(">> ");
        scanf("%d", &opt);
        getchar();
        if (opt < 1 || opt > 4)
            return 1;
    }
    while (opt < 1 || opt > 4);

    switch(opt)
    {
    case 1:
        while(add_order());
        break;
    case 2:
        system("cls");
        view();
        system("pause");
        break;
    case 3:
        while(remove_order());
        break;
    case 4:
        return 0;
    }

    return 1;
}
