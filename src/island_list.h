
#ifndef ISLAND_LIST_H
#define ISLAND_LIST_H

/*
typedef enum {
	unoccupied, human, computer
} city_player_t;
*/

struct island {
	//city_player_t playerId;
	gint playerId;
};

void island_list_add(gint);
void island_list_print();

//gboolean drawPiece(GtkWidget *widget, unit_type, player_type, gint, gint, gint);

#endif

