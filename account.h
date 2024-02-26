//
// Created by Äß on 2024/2/26.
//

#ifndef DROM_ACCOUNT_H
#define DROM_ACCOUNT_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define IDLENGTH 20
#define PASSWORDLENGTH 23
typedef struct account{ //
    char username[10];
    char password[10];
}account;
int EntryCheck(char* id, char* password);
int Login(char* studentId, char* studentPassword);

#endif //DROM_ACCOUNT_H
