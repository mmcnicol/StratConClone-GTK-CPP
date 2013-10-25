/* 
 * File:   grid.h
 * Author: matthew
 *
 * Created on 25 October 2013, 01:07
 */

#ifndef GRID_H
#define	GRID_H

class cGrid {
public:
    cGrid();
    //virtual ~grid();
    void generateMap(GtkWidget *widget);
    
    void drawMapMargin(GtkWidget *widget);
    void drawMap(GtkWidget *widget);
    void drawUnits(GtkWidget *widget);
    //void drawSeaGridlines(GtkWidget *widget);
    
private:
    
    void initMap(void);
    void addIslands(void);
    void defineIslandAsRandomPoly(gint iPlayerId, gint X, gint Y, gint w, gint h);


    GList* listNeighbour = NULL;
    void identify_unique_islands(void);
    void identify_cell_neighbours(gint, gint, gint);

    void AddCitiesToIslands(void);
    void AddCitiesToIslandListId(gint islandListId_);
    
};

#endif	/* GRID_H */

