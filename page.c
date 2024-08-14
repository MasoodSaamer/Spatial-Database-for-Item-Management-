/*
 * page.c : A source file including functions for page viewing
 */

#include "page.h"
#include <stdio.h>

void print_page(Item *result[], int size) {
    FILE *file = fopen("result.html", "w");
    if (file == NULL) {
        printf("Cannot open file result.html\n");
        return;
    }

    fprintf(file, "<html>\n<head>\n<title>Search Results</title>\n");
    fprintf(file, "<style>td { width: 30px; height: 30px; text-align: center; }</style>\n");
    fprintf(file, "</head>\n<body>\n");
    fprintf(file, "<table border=\"1\" style=\"background-image: url('nagoya.gif');\">\n");

    
    int grid_width = 30;
    int grid_height = 30;
    int map_width = 30;
    int map_height = 30;
    int grid[grid_height][grid_width];

    
    for (int i = 0; i < grid_height; i++) {
        for (int j = 0; j < grid_width; j++) {
            grid[i][j] = -1;
        }
    }

    
    for (int i = 0; i < size; i++) {
        if (result[i]->x < grid_width && result[i]->y < grid_height) {
            grid[result[i]->y][result[i]->x] = i;
        }
    }

    
    for (int i = 0; i < grid_height; i++) {
        fprintf(file, "<tr>");
        for (int j = 0; j < grid_width; j++) {
            if (grid[i][j] == -1) {
                fprintf(file, "<td></td>");
            } else {
                fprintf(file, "<td>%d</td>", grid[i][j]);
            }
        }
        fprintf(file, "</tr>\n");
    }

    fprintf(file, "</table>\n");

    fprintf(file, "<ul>\n");
    for (int i = 0; i < size; i++) {
        fprintf(file, "<li>%d: %s</li>\n", i, result[i]->name);
    }
    fprintf(file, "</ul>\n");

    fprintf(file, "</body>\n</html>\n");

    fclose(file);
    printf("Search results have been written to result.html\n");

}

