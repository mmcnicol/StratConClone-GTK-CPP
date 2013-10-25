/** pixmap.c **/
#include <gtk/gtk.h>
#include "city_list.h"

GSList* city_list = NULL;

void city_list_add(gint playerId, gint cellX, gint cellY, gint islandListId) {

    struct city *_city = g_new(struct city, 1);
    _city->playerId = playerId;
    _city->islandListId = islandListId;
    _city->cellX = cellX;
    _city->cellY = cellY;
    _city->productionUnitTypeId = -1;
    _city->productionDaysLeft = -1;
    _city->strength = 2;

    city_list = g_slist_append(city_list, _city);
}

void city_list_print() {

    GSList *iterator = NULL;
    int counter;

    g_print("city list:\n");
    for (counter = 0, iterator = city_list; iterator; iterator = iterator->next) {
        //struct city *_city = iterator->data;
        //g_print ("city %d,%d (playerId=%d)\n", _city->cellX, _city->cellY, _city->playerId );
        counter++;
    }
    g_print("count=%d\n", counter);
    g_slist_free(iterator);
}

/*
gboolean isCity(gint x, gint y) {

    GSList *iterator = NULL;
    int counter;

    //g_print("city list:\n");
    for (counter = 0, iterator = city_list; iterator; iterator = iterator->next) {
        
        //struct city *_city = iterator->data;
        //struct city _city = (city) iterator->data;
        //struct city *_city = (city*) iterator->data;
        //g_print ("city %d,%d (playerId=%d)\n", _city->cellX, _city->cellY, _city->playerId );
        
        //if ( _city->cellX==x && _city->cellY==y ) return TRUE;
        //if ( ((city*)iterator->data)->cellX==x && ((city*)iterator->data)->cellY==y ) return TRUE;
        //if ( ((city*)g_slist_nth(city_list, counter)->data)->cellX==x && ((city*)g_slist_nth(city_list, counter)->data)->cellY==y ) return TRUE;
        //if ( ((city*)g_slist_nth_data(city_list, counter))->cellX==x && ((city*)g_slist_nth_data(city_list, counter))->cellY==y ) return TRUE;
        
        counter++;
    }
    //g_print("count=%d\n", counter);
    g_slist_free(iterator);
    return FALSE;
}
*/

