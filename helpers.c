#include "helpers.h"

int burgerc[NBURGERS] = {0};
int pizzac[NPIZZAS] = {0};

int tot = 0;

const char *burgers[] =
{
    "Burger sapi",
    "Burger ayam",
    "Burger keju",
};

const char *pizzas[] = {
    "Pizza keju",
    "Pizza daging",
    "Pizza tuna",
};

const int burgerp[3] = {
    5, 5, 3
};

const int pizzap[3] = {
    10, 12, 14
};

int add_order(void)
{
    int opt;
    FILE *f = fopen("transactions.txt", "a");
    if (f == NULL)
        f = fopen("transactions.txt", "w");
    system("cls");
    printf("What do you want to order?\n");
    printf("1. Burgers\n");
    printf("2. Pizzas\n");
    printf("3. Exit\n");

    do
    {
        printf(">> ");
        scanf("%d", &opt);
        getchar();
    }
    while (opt < 1 || opt > 3);

    time_t now;
    time(&now);
    struct tm *now_tm = localtime(&now);
    char dbuff[16];
    strftime(dbuff, sizeof(dbuff), "%Y/%m/%d", now_tm);

    if (opt == 1)
    {
        system("cls");
        printf("Burgers in the menu:\n");

        for (int i = 0; i < NBURGERS; i++)
        {
            printf("%d. %s\n", i + 1, burgers[i]);
        }

        do
        {
            printf(">> ");
            scanf("%d", &opt);
            getchar();
        }
        while (opt < 1 || opt > NBURGERS);

        burgerc[opt - 1]++;
        tot += burgerp[opt - 1];
        fprintf(f, "[%s] %-25s %-16s - $%d\n", dbuff, "ORDERED 1 BURGER", burgers[opt - 1], burgerp[opt - 1]);
        printf("%s successfully ordered\n", burgers[opt - 1]);
        system("pause");
    }
    else if (opt == 2)
    {
        system("cls");
        printf("Pizzas in the menu:\n");

        for (int i = 0; i < NPIZZAS; i++)
        {
            printf("%d. %s\n", i + 1, pizzas[i]);
        }

        do
        {
            printf(">> ");
            scanf("%d", &opt);
            getchar();
        }
        while (opt < 1 || opt > NPIZZAS);

        pizzac[opt - 1]++;
        tot += pizzap[opt - 1];
        fprintf(f, "[%s] %-25s %-16s - $%d\n", dbuff, "ORDERED 1 PIZZA", pizzas[opt - 1], pizzap[opt - 1]);
        printf("%s successfully ordered\n", pizzas[opt - 1]);
        system("pause");
    }
    else
    {
        fclose(f);
        return 0;
    }

    fclose(f);
    return 1;
}

void view(char uname[48])
{
    printf("%-25s: %s\n", "Customer", uname);
    printf("Burgers:\n");
    for (int i = 0; i < NBURGERS; i++)
    {
        printf("%-25s: %-4d orders\n", burgers[i], burgerc[i]);
    }
    printf("==================================================\n");
    printf("Pizzas:\n");
    for (int i = 0; i < NPIZZAS; i++)
    {
        printf("%-25s: %-4d order(s)\n", pizzas[i], pizzac[i]);
    }
    printf("==================================================\n");
    printf("%-25s: $%d\n", "Total", tot);
}

int remove_order(void)
{
    int opt;
    int rm;
    FILE *f = fopen("transactions.txt", "a");
    if (f == NULL)
        f = fopen("transactions.txt", "w");
    system("cls");
    printf("What do you want to remove?\n");
    printf("1. Burgers\n");
    printf("2. Pizzas\n");
    printf("3. Exit\n");

    do
    {
        printf(">> ");
        scanf("%d", &opt);
        getchar();
        if (opt < 1 || opt > 3)
            return 1;
    }
    while(opt < 1 || opt > 3);

    time_t now;
    time(&now);
    struct tm *now_tm = localtime(&now);
    char dbuff[16];
    strftime(dbuff, sizeof(dbuff), "%Y/%m/%d", now_tm);

    if (opt == 1)
    {
        system("cls");
        for (int i = 0; i < NBURGERS; i++)
        {
            printf("%d. %-25s : %-4d orders\n", i + 1, burgers[i], burgerc[i]);
        }
        printf("What do you want to remove? [0 to exit]");
        do
        {
            scanf("%d", &opt);
            getchar();

            if (opt == 0)
            {
                fclose(f);
                return 0;
            }
        }
        while (opt < 1 || opt > NBURGERS || burgerc[opt - 1] == 0);
        burgerc[opt - 1]--;
        tot -= burgerp[opt - 1];
        fprintf(f, "[%s] %-25s %-16s - %d\n", dbuff, "REMOVED 1 BURGER", burgers[opt - 1], burgerp[opt - 1]);
        printf("%s successfully removed\n", burgers[opt - 1]);
        system("pause");
    }
    else if (opt == 2)
    {
        system("cls");
        for (int i = 0; i < NPIZZAS; i++)
        {
            printf("%d. %-25s : %-4d orders\n", i + 1, pizzas[i], pizzac[i]);
        }
        printf("What do you want to remove? ");
        do
        {
            scanf("%d", &opt);
            getchar();
        }
        while (opt < 1 || opt > NPIZZAS || pizzac[opt - 1] == 0);
        pizzac[opt - 1]--;
        tot -= pizzap[opt - 1];
        fprintf(f, "[%s] %-25s %-16s - $%d\n", dbuff, "REMOVED 1 PIZZA", pizzas[opt - 1], pizzap[opt - 1]);
        printf("%s successfully removed\n", pizzas[opt - 1]);
        system("pause");
    }
    else
    {
        fclose(f);
        return 0;
    }

    fclose(f);
    return 1;
}

void exitt(char uname[48])
{
    FILE *f = fopen("transactions.txt", "a");
    if (f == NULL)
        f = fopen("transactions.txt", "w");
    fprintf(f, "FINAL TOTAL: $%d\n", tot);
    fprintf(f, "CUSTOMER NAME: %s\n", uname);
    fprintf(f, "=======================================\n");
    fclose(f);
}
