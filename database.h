/*
 * database.h : A header file to share function prototype for database accesses
 */
#ifndef DATABASE_H
#define DATABASE_H

/* this header file depends on item.h */
#include "item.h"
#include <math.h>
#include "page.h"

/*
 * Macro defitions related to database
 */

/* Macro definition for the maximum size of database */
#define MAX_ITEM_SIZE 100 

/* Macro definition for the maximum length of file path (loading/saving) */
#define MAX_FILE_PATH_LENGTH 30


void insert_item();
void print_all_items();
void load_items();
void save_items();
void find_items_by_name();
void find_items_by_category();
void find_items_by_range();
void find_nearest_neighbor();
void find_items_by_partial_name();

#endif
