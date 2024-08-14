//MASOOD Saamer 082240793
//Computer Software 2
//Project 1st Milestone v1 - 4/7/2024

/*
 * item.h : A header file to share the definition of Structure Item
 */

#ifndef ITEM_H
#define ITEM_H

#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 50
#define MAX_X_COORDINATE 100
#define MAX_Y_COORDINATE 100

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    char category[MAX_CATEGORY_LENGTH + 1];
    int x;
    int y;
} Item;

#endif
