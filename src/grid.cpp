/* 
 * File:   grid.cpp
 * Author: matthew
 * 
 * Created on 25 October 2013, 01:07
 */
#include <gtk/gtk.h>
#include "grid.h"
#include "pieces.h"
#include "includes.h"
#include "island_list.h"
#include "city_list.h"
#include <math.h>
#include <iostream>

using namespace std;

extern GSList* island_list;
extern GSList* city_list;


cGridCell *oGridCell = new cGridCell(0, 0);

struct cell_class cell[MAP_WIDTH][MAP_HEIGHT];

cGrid::cGrid() {
}

/*
grid::~grid() {
}
 */


void cGrid::generateMap(GtkWidget *widget) {

    initMap();

    addIslands();

    identify_unique_islands();

    AddCitiesToIslands();

    //island_list_add(-1);
    //island_list_add(-2);
    //island_list_add(-3);
    island_list_print();

    //city_list_add(1, 1, 1);
    //city_list_add(1, 2, 3);
    //city_list_add(2, 31, 32);
    city_list_print();

}

void cGrid::initMap(void) {

    int x, y;

    for (y = 0; y < MAP_HEIGHT; y = y + 1) {
        for (x = 0; x < MAP_WIDTH; x = x + 1) {

            cell[x][y].isLand = FALSE;
            cell[x][y].isFogOfWar = FALSE;
            cell[x][y].islandId = 0;
        }
    }
}

void cGrid::addIslands(void) {

    defineIslandAsRandomPoly(1, UNIT_WIDTH * (int) GetRand(35, 45), UNIT_HEIGHT * (int) GetRand(20, 25), UNIT_WIDTH * (int) GetRand(4, 5), UNIT_HEIGHT * (int) GetRand(4, 5));

    defineIslandAsRandomPoly(2, UNIT_WIDTH * (int) GetRand(65, 75), UNIT_HEIGHT * (int) GetRand(40, 45), UNIT_WIDTH * (int) GetRand(3, 4), UNIT_HEIGHT * (int) GetRand(3, 4));

    int i, j;
    for (i = 5; i < MAP_WIDTH; i = i + 12) {
        for (j = 5; j < MAP_HEIGHT; j = j + 14) {
            switch ((int) GetRand(1, 4)) {
                case 1:
                    if ((int) GetRand(1, 1000) % 2 == 0) defineIslandAsRandomPoly(-1, UNIT_WIDTH * (int) GetRand(i - 5, i + 5), UNIT_HEIGHT * (int) GetRand(j - 5, j + 5), UNIT_WIDTH * (int) GetRand(2, 5), UNIT_HEIGHT * (int) GetRand(2, 5));
                    break;
                case 2:
                    if ((int) GetRand(1, 1000) % 3 == 0) defineIslandAsRandomPoly(-1, UNIT_WIDTH * (int) GetRand(i - 5, i + 5), UNIT_HEIGHT * (int) GetRand(j - 5, j + 5), UNIT_WIDTH * (int) GetRand(3, 6), UNIT_HEIGHT * (int) GetRand(3, 6));
                    break;
                case 3:
                    if ((int) GetRand(1, 1000) % 2 == 0) defineIslandAsRandomPoly(-1, UNIT_WIDTH * (int) GetRand(i - 5, i + 5), UNIT_HEIGHT * (int) GetRand(j - 5, j + 5), UNIT_WIDTH * (int) GetRand(4, 7), UNIT_HEIGHT * (int) GetRand(5, 8));
                    break;
                case 4:
                    if ((int) GetRand(1, 1000) % 2 == 0) defineIslandAsRandomPoly(-1, UNIT_WIDTH * (int) GetRand(i - 5, i + 5), UNIT_HEIGHT * (int) GetRand(j - 5, j + 5), UNIT_WIDTH * (int) GetRand(5, 8), UNIT_HEIGHT * (int) GetRand(7, 9));
                    break;
            }
        }
    }

}

void cGrid::defineIslandAsRandomPoly(gint iPlayerId, gint X, gint Y, gint w, gint h) {

    // create a poly (island)
    float deg = 0, deg2;
    int x, y, xx, yy, xxx, yyy, rand_number, count = 0; // , prevX=0, prevY=0, cityCount=0;

    int intX[50];
    int intY[50];

    //int a=0,b=0;

    do {
        //console.log( "count=" + count );
        x = RoundToInt(w * cos(deg));
        y = RoundToInt(h * sin(deg));

        //a=X+x;
        //b=Y+y;
        intX[count] = X + x;
        intY[count] = Y + y;

        //prevX=a;
        //prevY=b;

        rand_number = GetRand(5, 8);
        deg2 = (float) rand_number / 10;
        //deg += 0.5; //0.005;
        deg += deg2;
        count = count + 1;

    } while (deg <= 6.4 && count < 50);

    //if ( GridDrawMode==2 ) oIslandPolyList.Add(intX, intY, count);


    // for each cell that is within the rectangle (that contains the poly)
    // credits: amended version of 'point in poly' algorithm by Randolph Franklin
    for (xx = X - w; xx <= (int) X + w; xx = xx + UNIT_WIDTH) {

        for (yy = Y - h; yy <= (int) Y + h; yy = yy + UNIT_HEIGHT) {


            // next identify if this cell is within the poly (island)
            int npol = count, x = xx + (UNIT_WIDTH / 2), y = yy + (UNIT_HEIGHT / 2);

            int i, j, c = 0;

            for (i = 0, j = npol - 1; i < npol; j = i++) {

                int intXI = intX[i];
                int intXJ = intX[j];

                int intYI = intY[i];
                int intYJ = intY[j];


                if ((((intYI <= y) && (y < intYJ)) ||
                        ((intYJ <= y) && (y < intYI))) &&
                        (x < (intXJ - intXI) * (y - intYI) / (intYJ - intYI) + intXI)) {
                    c = !c;
                }

            }

            // if point is in poly, mark GridCellType as Land (code 1)
            if (c == 1) {

                xxx = ceil((xx) / UNIT_WIDTH);
                yyy = ceil((yy) / UNIT_HEIGHT);

                if (xxx >= 0 && yyy >= 0 && xxx < MAP_WIDTH && yyy < MAP_HEIGHT) {
                    //intGridCellType[xxx][yyy]=1;
                    cell[xxx][yyy].isLand = TRUE;
                    cell[xxx][yyy].islandId = -1;
                }
            }
        }
    }
}

void cGrid::identify_unique_islands(void) {

    gint x, y, islandListId = 0;
    GList *tmp;

    for (y = 0; y <= MAP_HEIGHT; y = y + 1) {
        for (x = 0; x <= MAP_WIDTH; x = x + 1) {

            if (cell[x][y].isLand == TRUE && cell[x][y].islandId == -1) {
                cell[x][y].islandId = islandListId;
                //cout << "cell(" << x << "," << y << ") islandListId" << islandListId << endl;



                identify_cell_neighbours(x, y, islandListId);

                //cout << "g_list_length(listNeighbour)=" << g_list_length(listNeighbour) << endl;


                //gint tempCounter=10;
                while (g_list_length(listNeighbour) > 0) {

                    //tempCounter--;
                    //if(tempCounter==0) break;
                    //if(g_list_length(listNeighbour)==0) break;


                    for (int i = 0; i < g_list_length(listNeighbour); i++) {
                        //cGridCell oGridCell = (cGridCell) listNeighbour.get(i);
                        //cGridCell tempGridCell = new cGridCell(g_list_nth(listNeighbour, i)->data->getX(), g_list_nth(listNeighbour, i)->data->getY());
                        tmp = g_list_nth(listNeighbour, i);

                        //UpdateGridIslandsDetail(oGridCell.getX(),oGridCell.getY(),iIslandListId);
                        identify_cell_neighbours(((cGridCell *) tmp->data)->getX(), ((cGridCell *) tmp->data)->getY(), islandListId);
                        //listNeighbour.remove(i);
                        //listNeighbour = g_list_remove_all(listNeighbour, g_list_nth(listNeighbour, i));
                        listNeighbour = g_list_remove_link(listNeighbour, tmp);
                        listNeighbour = g_list_remove(listNeighbour, tmp);
                        //cout << i << " after remove... g_list_length(listNeighbour)=" << g_list_length(listNeighbour) << endl;
                    }

                    //cout << "g_list_length(listNeighbour)=" << g_list_length(listNeighbour) << endl;

                }
                //g_list_free(listNeighbour);


                //oIslandList.AddIsland(-1); // add an island to IslandList which is not assigned to any player
                island_list_add(-1); // add an island to IslandList which is not assigned to any player



                islandListId = islandListId + 1;
            }
        }
    }

    g_list_free(tmp);
}

void cGrid::identify_cell_neighbours(gint x_, gint y_, gint iIslandListId_) {

    if (x_ - 1 >= 0)
        if (cell[x_ - 1][y_].isLand == TRUE && cell[x_ - 1][y_].islandId == -1) {
            cell[x_ - 1][y_].islandId = iIslandListId_;
            //cout << "cell(" << x_-1 << "," << y_ << ") islandListId" << iIslandListId_ << endl;
            listNeighbour = g_list_insert(listNeighbour, new cGridCell(x_ - 1, y_), 0);
        }

    if (x_ + 1 <= MAP_WIDTH)
        if (cell[x_ + 1][y_].isLand == TRUE && cell[x_ + 1][y_].islandId == -1) {
            cell[x_ + 1][y_].islandId = iIslandListId_;
            //cout << "cell(" << x_+1 << "," << y_ << ") islandListId" << iIslandListId_ << endl;
            listNeighbour = g_list_insert(listNeighbour, new cGridCell(x_ + 1, y_), 0);
        }


    if (y_ - 1 >= 0)
        if (cell[x_][y_ - 1].isLand == TRUE && cell[x_][y_ - 1].islandId == -1) {
            cell[x_][y_ - 1].islandId = iIslandListId_;
            //cout << "cell(" << x_ << "," << y_-1 << ") islandListId" << iIslandListId_ << endl;
            listNeighbour = g_list_insert(listNeighbour, new cGridCell(x_, y_ - 1), 0);
        }

    if (y_ + 1 <= MAP_HEIGHT)
        if (cell[x_][y_ + 1].isLand == TRUE && cell[x_][y_ + 1].islandId == -1) {
            cell[x_][y_ + 1].islandId = iIslandListId_;
            //cout << "cell(" << x_ << "," << y_+1 << ") islandListId" << iIslandListId_ << endl;
            listNeighbour = g_list_insert(listNeighbour, new cGridCell(x_, y_ + 1), 0);
        }



    if (x_ - 1 >= 0 && y_ - 1 >= 0)
        if (cell[x_ - 1][y_ - 1].isLand == TRUE && cell[x_ - 1][y_ - 1].islandId == -1) {
            cell[x_ - 1][y_ - 1].islandId = iIslandListId_;
            //cout << "cell(" << x_-1 << "," << y_-1 << ") islandListId" << iIslandListId_ << endl;
            listNeighbour = g_list_insert(listNeighbour, new cGridCell(x_ - 1, y_ - 1), 0);
        }

    if (x_ + 1 <= MAP_WIDTH && y_ + 1 <= MAP_HEIGHT)
        if (cell[x_ + 1][y_ + 1].isLand == TRUE && cell[x_ + 1][y_ + 1].islandId == -1) {
            cell[x_ + 1][y_ + 1].islandId = iIslandListId_;
            //cout << "cell(" << x_+1 << "," << y_+1 << ") islandListId" << iIslandListId_ << endl;
            listNeighbour = g_list_insert(listNeighbour, new cGridCell(x_ + 1, y_ + 1), 0);
        }


    if (x_ - 1 >= 0 && y_ + 1 <= MAP_HEIGHT)
        if (cell[x_ - 1][y_ + 1].isLand == TRUE && cell[x_ - 1][y_ + 1].islandId == -1) {
            cell[x_ - 1][y_ + 1].islandId = iIslandListId_;
            //cout << "cell(" << x_-1 << "," << y_+1 << ") islandListId" << iIslandListId_ << endl;
            listNeighbour = g_list_insert(listNeighbour, new cGridCell(x_ - 1, y_ + 1), 0);
        }

    if (x_ + 1 <= MAP_WIDTH && y_ - 1 >= 0)
        if (cell[x_ + 1][y_ - 1].isLand == TRUE && cell[x_ + 1][y_ - 1].islandId == -1) {
            cell[x_ + 1][y_ - 1].islandId = iIslandListId_;
            //cout << "cell(" << x_+1 << "," << y_-1 << ") islandListId" << iIslandListId_ << endl;
            listNeighbour = g_list_insert(listNeighbour, new cGridCell(x_ + 1, y_ - 1), 0);
        }

}

void cGrid::AddCitiesToIslands() {

    //if (debugCityAdd) println("in cGrid.AddCitiesToIslands() ");

    // for each island
    //g_list_foreach(&island_list, AddCitiesToIslandListId, NULL);

    GSList *iterator = NULL;
    int counter;

    //g_print("island list:\n");
    for (counter = 0, iterator = island_list; iterator; iterator = iterator->next) {
        //struct island *_island = iterator->data;
        //g_print ("island (playerId=%d)\n", _island->playerId );
        AddCitiesToIslandListId(counter);
        counter++;
    }
    //g_print("count=%d\n", counter);
    g_slist_free(iterator);

    /*
    gint i=0;
    for (i=1; i<=oIslandList.getCount(); i=i+1) {

        //if (debugCityAdd) println("debug in cGrid.AddCitiesToIslands() CityIslandListId="+i);

        AddCitiesToIslandListId(i);
    }
     */

    //if (debugCityAdd) println("leaving cGrid.AddCitiesToIslands() ");		
}


//void AddCitiesToIslandListId(gpointer data) {

void cGrid::AddCitiesToIslandListId(gint islandListId_) {

    cout << "in AddCitiesToIslandListId(" << islandListId_ << ")" << endl;
    //int *data = (int*) data ;
    //gint islandListId_ = g_list_index(g_list_foreach, data);

    gint x, y;
    gint maxCityPerIsland = (int) GetRand(3, 8);
    cout << "maxCityPerIsland=" << maxCityPerIsland << endl;
    //int intRandomNumber = round(random(1,3));
    gint iAddCityToIsland;
    gint cityCount = 0;


    // scan through grid
    for (y = 0; y <= MAP_HEIGHT; y = y + 1) {
        for (x = 0; x <= MAP_WIDTH; x = x + 1) {

            if (cell[x][y].islandId == islandListId_ && cityCount < maxCityPerIsland) {

                iAddCityToIsland = (int) (GetRand(1, 1000) % 7);

                //cout << "iAddCityToIsland=" << iAddCityToIsland << endl;


                        
                if (iAddCityToIsland == 0) {

                        city_list_add(-1, x, y, islandListId_);
                
                        cityCount = maxCityPerIsland;
                
                    //island_list_add(-1, x, y, islandListId_);

                    //oIslandList.setPlayerId(islandListId_, intPlayerId);

                    //cityCount++;

                    //cout << "iAddCityToIsland=" << iAddCityToIsland << endl;
                    //cout << "about to call island_list_add, x=" << x << ", y=" << y << endl;
                    //cout << "about to call island_list_add, x=" << x << ", y=" << y << "islandListId_=" << islandListId_ << endl;

                    /*
                // game rule: cities should not be immediately next to each other
                //if (oCityList.getCountCityNearby(1, x, y) == 0 && oCityList.getCountCityNearby(2, x, y) == 0) {
                if (1) {

                    //if (debugCityAdd) println(" debug in cGrid.AddCitiesToIslandListId() islandListId_=" + islandListId_);
                        
                    //oCityList.AddCity(-1, x, y, islandListId_);
                    island_list_add(-1, x, y, islandListId_);

                    //oIslandList.setPlayerId(islandListId_, intPlayerId);

                    cityCount++;
                }
                     */
                }


            }

        }
    }
}

void cGrid::drawMapMargin(GtkWidget *widget) {

    gint x, y;
    gchar temp_string[3];

    GdkColor colourMarginBg;
    //gdk_color_parse ("#EAEAEA", &colourMarginBg);
    gdk_color_parse("#404445", &colourMarginBg);

    GdkColor colourMarginFg;
    //gdk_color_parse ("#35AE29", &colourMarginFg);
    gdk_color_parse("#EAEAEA", &colourMarginFg);


    GdkGC *MarginBg_gc;
    MarginBg_gc = gdk_gc_new(widget->window);
    gdk_gc_set_rgb_fg_color(MarginBg_gc, &colourMarginBg);

    GdkGC *MarginFg_gc;
    MarginFg_gc = gdk_gc_new(widget->window);
    gdk_gc_set_rgb_fg_color(MarginFg_gc, &colourMarginFg);


    GdkFont *font;
    font = gdk_font_load("-misc-fixed-medium-r-*-*-*-70-*-*-*-*-*-*");


    // draw x margin
    //gdk_draw_rectangle (widget->window, MarginBg_gc, 1, 
    //	MAP_OFFSET_X-UNIT_WIDTH, MAP_OFFSET_Y-UNIT_HEIGHT, MAP_WIDTH*UNIT_WIDTH, MAP_HEIGHT*UNIT_HEIGHT); 

    gdk_draw_rectangle(widget->window, MarginBg_gc, 1,
            0, 0, MAP_WIDTH*UNIT_WIDTH, UNIT_HEIGHT);


    y = 0;
    for (x = 0; x < MAP_WIDTH; x = x + 1) {

        // convert integer value to string
        sprintf(temp_string, "%d", x + 1);

        // draw string
        gdk_draw_string(widget->window, font, MarginFg_gc,
                MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH) + 4,
                MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT) - 3,
                temp_string);

    }

    // draw y margin
    gdk_draw_rectangle(widget->window, MarginBg_gc, 1,
            0, 0, UNIT_WIDTH, MAP_HEIGHT * UNIT_HEIGHT);

    x = 0;
    for (y = 0; y < MAP_HEIGHT; y = y + 1) {

        // convert integer value to string
        sprintf(temp_string, "%d", y + 1);

        // draw string
        gdk_draw_string(widget->window, font, MarginFg_gc,
                MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH) - UNIT_WIDTH + 4,
                MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT) + UNIT_HEIGHT - 3,
                temp_string);

    }
}

void cGrid::drawMap(GtkWidget *widget) {

    gint unit_count;
    unit_type unit;
    player_type player;
    
    
    int x, y;

    GdkColor colourSea;
    gdk_color_parse("#15ABE4", &colourSea);

    GdkColor colourLand;
    gdk_color_parse("#35AE29", &colourLand);


    GdkGC *sea_gc;
    sea_gc = gdk_gc_new(widget->window);
    gdk_gc_set_rgb_fg_color(sea_gc, &colourSea);

    GdkGC *land_gc;
    land_gc = gdk_gc_new(widget->window);
    gdk_gc_set_rgb_fg_color(land_gc, &colourLand);

    


    
#if DEBUG_ISLANDLISTID
    char temp_string[5];

    GdkColor colourMarginBg;
    //gdk_color_parse ("#EAEAEA", &colourMarginBg);
    gdk_color_parse("#404445", &colourMarginBg);

    GdkColor colourMarginFg;
    //gdk_color_parse ("#35AE29", &colourMarginFg);
    gdk_color_parse("#EAEAEA", &colourMarginFg);


    GdkGC *MarginBg_gc;
    MarginBg_gc = gdk_gc_new(widget->window);
    gdk_gc_set_rgb_fg_color(MarginBg_gc, &colourMarginBg);

    GdkGC *MarginFg_gc;
    MarginFg_gc = gdk_gc_new(widget->window);
    gdk_gc_set_rgb_fg_color(MarginFg_gc, &colourMarginFg);


    GdkFont *font;
    font = gdk_font_load("-misc-fixed-medium-r-*-*-*-70-*-*-*-*-*-*");
#endif

    //gint unit_count;
    //unit_type unit;
    //player_type player;

    //player=human;
    //unit=army;
    //unit_count=0;


    for (y = 0; y < MAP_HEIGHT; y = y + 1) {
        for (x = 0; x < MAP_WIDTH; x = x + 1) {

            /* if (x==4) {
                    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X+((x+1)*UNIT_WIDTH), MAP_OFFSET_Y+((y+1)*UNIT_HEIGHT));
            } else if (x==6) {
                    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X+((x+1)*UNIT_WIDTH), MAP_OFFSET_Y+((y+1)*UNIT_HEIGHT));
            } else */ 
            
            if (cell[x][y].isLand == TRUE) {
                
                
                /*
                    player = human, x = 1;
                    unit = army;
                    unit_count = 0, y = 1;

                    unit = city;
                    y = 17;
                    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT));
                */
                
                
                gdk_draw_rectangle(widget->window, land_gc, 1,
                        MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT), UNIT_WIDTH, UNIT_HEIGHT);



#if DEBUG_ISLANDLISTID
                // to debug islandId...
                sprintf(temp_string, "%d", cell[x][y].islandId);

                // draw string
                gdk_draw_string(widget->window, font, MarginFg_gc,
                        MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH),
                        MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT) + UNIT_HEIGHT,
                        temp_string);
#endif

            } else {
                gdk_draw_rectangle(widget->window, sea_gc, 1,
                        MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT), UNIT_WIDTH, UNIT_HEIGHT);
            }

        }
    }
}

void cGrid::drawUnits(GtkWidget *widget) {

    gint x = 0, y = 0;

    gint unit_count;
    unit_type unit;
    player_type player;

    // draw player 1 (human) pieces
    player = human, x = 1;
    unit = army;
    unit_count = 0, y = 1;
    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT));

    unit = destroyer;
    unit_count = 1, y = 3;
    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT));

    unit = submarine;
    unit_count = 2, y = 5;
    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT));

    unit = transport;
    unit_count = 9, y = 7;
    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT));

    unit = carrier;
    unit_count = 10, y = 9;
    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT));

    unit = battleship;
    unit_count = 100, y = 11;
    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT));

    unit = fighter;
    unit_count = 0, y = 13;
    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT));

    unit = bomber;
    y = 15;
    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT));

    unit = city;
    y = 17;
    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT));


    // draw player 2 (computer) pieces
    player = computer, x = 3;
    unit = army;
    unit_count = 0, y = 1;
    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT));

    unit = destroyer;
    unit_count = 1, y = 3;
    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT));

    unit = submarine;
    unit_count = 2, y = 5;
    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT));

    unit = transport;
    unit_count = 9, y = 7;
    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT));

    unit = carrier;
    unit_count = 10, y = 9;
    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT));

    unit = battleship;
    unit_count = 100, y = 11;
    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT));

    unit = fighter;
    unit_count = 0, y = 13;
    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT));

    unit = bomber;
    y = 15;
    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT));

    unit = city;
    y = 17;
    drawPiece(widget, unit, player, unit_count, MAP_OFFSET_X + ((x + 1) * UNIT_WIDTH), MAP_OFFSET_Y + ((y + 1) * UNIT_HEIGHT));
}

