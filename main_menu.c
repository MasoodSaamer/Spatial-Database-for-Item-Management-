//MASOOD Saamer 082240793
//Computer Software 2
//Project 1st Milestone

/*
 * main_menu.c : A Source file of main function
 */

#include "database.h"
#include <stdio.h>

void show_menu() {
    printf("Main Menu\n");
    printf("i: Insert a new item\n");
    printf("p: Print all items\n");
    printf("l: Load items from a file\n");
    printf("s: Save items to a file\n");
    printf("f: Find items by name\n");
    printf("c: Find items by category\n");
    printf("r: Range search\n");
    printf("n: Nearest neighbor search\n");
    printf("o: Partial name search\n");
    printf("q: Quit\n");
}

int main() {
    char choice;
    
    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        getchar(); 
        
        switch (choice) {
            case 'i':
                insert_item();
                break;
            case 'p':
                print_all_items();
                break;
            case 'l':
                load_items();
                break;
            case 's':
                save_items();
                break;
            case 'f':
                find_items_by_name();
                break;
            case 'c':
                find_items_by_category();
                break;
            case 'r':
                find_items_by_range();
                break;
            case 'n':
                find_nearest_neighbor();
                break;
            case 'o':
                find_items_by_partial_name();
                break;
            case 'q':
                return 0;
            default:
                printf("Illegal choice. Please try again.\n");
        }
    }
}
