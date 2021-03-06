/** pixmap.c **/
#include <gtk/gtk.h>
#include "island_list.h"
#include "includes.h"
//#include <math.h>

GSList* island_list = NULL;


void island_list_add(gint iPlayerId_) {

    //struct island *_island = (struct island*)malloc(sizeof(struct island));
    struct island *_island = g_new(struct island, 1);
    //struct island _island;	
    _island->iPlayerId = iPlayerId_;

    island_list = g_slist_append(island_list, _island);
}

void island_list_add(gint iPlayerId_, gint iCellX_, gint iCellY_, gint iIslandListId_) {

    //struct island *_island = (struct island*)malloc(sizeof(struct island));
    struct island *_island = g_new(struct island, 1);
    //struct island _island;	
    _island->iPlayerId = iPlayerId_;

    island_list = g_slist_append(island_list, _island);
}


void island_list_print() {

    GSList *iterator = NULL;
    int counter;

    g_print("island list:\n");
    for (counter = 0, iterator = island_list; iterator; iterator = iterator->next) {
        //struct island *_island = iterator->data;
        //g_print ("island (playerId=%d)\n", _island->playerId );
        counter++;
    }
    g_print("count=%d\n", counter);
    g_slist_free(iterator);
}

