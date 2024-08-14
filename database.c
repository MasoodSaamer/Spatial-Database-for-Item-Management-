//MASOOD Saamer 082240793
//Computer Software 2
//Project 1st Milestone

/*
 * database.h : A header file to share function prototype for database accesses
 */

#include "database.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "page.h"

#define MAX_ITEM_SIZE 100

static Item items[MAX_ITEM_SIZE];
static int item_count = 0;

void insert_item() {
    if (item_count >= MAX_ITEM_SIZE) {
        printf("Database is full!\n");
        return;
    }
    
    Item new_item;
    
    printf("Enter the name of the item: ");
    fgets(new_item.name, MAX_NAME_LENGTH, stdin);
    new_item.name[strcspn(new_item.name, "\n")] = '\0'; 
    
    printf("Enter the category of the item: ");
    fgets(new_item.category, MAX_CATEGORY_LENGTH, stdin);
    new_item.category[strcspn(new_item.category, "\n")] = '\0'; 
    
    printf("Enter the x-coordinate: ");
    scanf("%d", &new_item.x);
    
    printf("Enter the y-coordinate: ");
    scanf("%d", &new_item.y);
    
    getchar(); 
    
    items[item_count++] = new_item;
}

void print_all_items() {
    printf("|%-30s|%-20s|%-9s|\n", "Item name", "Category", "Position");
    printf("+------------------------------+--------------------+---------+\n");
    
    for (int i = 0; i < item_count; i++) {
        printf("|%-30s|%-20s|(%3d, %3d)|\n", items[i].name, items[i].category, items[i].x, items[i].y);
    }

}

void load_items() {
    char filename[100];
    FILE *file;

    printf("Enter a file name for loading: ");
    scanf("%s", filename);
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file %s\n", filename);
        return;
    }

    item_count = 0;
    while (fscanf(file, "%[^,],%[^,],%d,%d\n", items[item_count].name, items[item_count].category, &items[item_count].x, &items[item_count].y) != EOF) {
        item_count++;
        if (item_count >= MAX_ITEM_SIZE) {
            printf("Database is full! Some items may not be loaded.\n");
            break;
        }
    }

    fclose(file);
}

void save_items() {
    char filename[100];
    FILE *file;

    printf("Enter a file name for saving: ");
    scanf("%s", filename);
    
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Cannot open file %s\n", filename);
        return;
    }

    for (int i = 0; i < item_count; i++) {
        fprintf(file, "%s,%s,%d,%d\n", items[i].name, items[i].category, items[i].x, items[i].y);
    }

    fclose(file);
}


void find_items_by_name() {
    char search_name[MAX_NAME_LENGTH + 1];
    Item *result[MAX_ITEM_SIZE];
    int num_result = 0;

    printf("Enter an item name for searching: ");
    fgets(search_name, MAX_NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = '\0'; 

    for (int i = 0; i < item_count; i++) {
        if (strcmp(items[i].name, search_name) == 0) {
            result[num_result++] = &items[i];
        }
    }

    print_page(result, num_result);
}

void find_items_by_category() {
    char search_category[MAX_CATEGORY_LENGTH + 1];
    Item *result[MAX_ITEM_SIZE];
    int num_result = 0;

    printf("Enter a category for searching: ");
    fgets(search_category, MAX_CATEGORY_LENGTH, stdin);
    search_category[strcspn(search_category, "\n")] = '\0'; 

    for (int i = 0; i < item_count; i++) {
        if (strcmp(items[i].category, search_category) == 0) {
            result[num_result++] = &items[i];
        }
    }

    print_page(result, num_result);
}


void find_items_by_range() {
    int user_x, user_y, threshold;
    Item *result[MAX_ITEM_SIZE];
    int num_result = 0;

    printf("Enter your x-coordinate: ");
    scanf("%d", &user_x);
    printf("Enter your y-coordinate: ");
    scanf("%d", &user_y);
    printf("Enter distance threshold (m): ");
    scanf("%d", &threshold);

    for (int i = 0; i < item_count; i++) {
        int dx = items[i].x - user_x;
        int dy = items[i].y - user_y;
        double distance = sqrt(dx * dx + dy * dy) * 40.0; // I took the assumption of 40 meters per grid
        if (distance <= threshold) {
            result[num_result++] = &items[i];
        }
    }

    print_page(result, num_result);
}

void find_nearest_neighbor() {
    int user_x, user_y;
    Item *result[MAX_ITEM_SIZE];
    int num_result = 0;
    double min_distance = -1.0;

    printf("Enter your x-coordinate: ");
    scanf("%d", &user_x);
    printf("Enter your y-coordinate: ");
    scanf("%d", &user_y);

    for (int i = 0; i < item_count; i++) {
        int dx = items[i].x - user_x;
        int dy = items[i].y - user_y;
        double distance = sqrt(dx * dx + dy * dy) * 40.0;
        if (min_distance < 0 || distance < min_distance) {
            min_distance = distance;
            num_result = 0;
            result[num_result++] = &items[i];
        } else if (distance == min_distance) {
            result[num_result++] = &items[i];
        }
    }

    print_page(result, num_result);
}

//This function basically searches the location based on partial name provided by the user.
//For example, if the user inputs "CO-OP", the function will search all the items containing "CO-OP" in their title.
//And it will output all those results
void find_items_by_partial_name() {
    char search_name[MAX_NAME_LENGTH + 1];
    Item *result[MAX_ITEM_SIZE];
    int num_result = 0;

    printf("Enter a partial name for searching: ");
    fgets(search_name, MAX_NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = '\0'; 

    for (int i = 0; i < item_count; i++) {
        if (strstr(items[i].name, search_name) != NULL) {
            result[num_result++] = &items[i];
        }
    }

    print_page(result, num_result);
}


 
