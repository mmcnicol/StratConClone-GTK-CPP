
#ifndef CITY_LIST_H
#define CITY_LIST_H

/*
typedef enum {
	unoccupied, human, computer
} city_player_t;
*/

struct city {
	//city_player_t playerId;
	gint playerId;
	gint islandListId;
	gint cellX, cellY;
	gint productionUnitTypeId;
	gint productionDaysLeft;
	gint strength;
};

void city_list_add(gint, gint, gint);
void city_list_print();

//gboolean drawPiece(GtkWidget *widget, unit_type, player_type, gint, gint, gint);

#endif

