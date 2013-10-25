
#ifndef ISLAND_LIST_H
#define ISLAND_LIST_H

/*
typedef enum {
	unoccupied, human, computer
} city_player_t;
*/

struct island {
	//city_player_t playerId;
	gint iPlayerId;
        gint iCellX;
        gint iCellY;
        gint iIslandListId;
};

void island_list_add(gint iPlayerId_);
void island_list_add(gint iPlayerId_, gint iCellX_, gint iCellY_, gint iIslandListId_);
void island_list_print();

void AddCitiesToIslands();

//void AddCitiesToIslandListId(gpointer data);
void AddCitiesToIslandListId(gint);

//gboolean drawPiece(GtkWidget *widget, unit_type, player_type, gint, gint, gint);

#endif

