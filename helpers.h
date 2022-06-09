#ifndef HELPERS
#define HELPERS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NBURGERS 3 // jumlah di menu
#define NPIZZAS 3 // jumlah di menu

int menu(char uname[48]);
int add_order(void);
void view(char uname[48]);
int remove_order(void);
void exitt(char uname[48]);

#endif
