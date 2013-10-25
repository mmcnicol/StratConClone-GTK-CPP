/* 
 * File:   main.cpp
 * Author: matthew
 *
 * Created on 18 October 2013, 01:02
 */

/** layout.c **/
#include <gtk/gtk.h>
#include "pieces.h"
//#include "island_list.h"
#include "city.h"
//#include "city_list.h"
#include "unit_ref.h"
#include "grid.h"
#include "includes.h"
#include <stdlib.h>
#include <math.h>
#include <iostream>
//#include <gnome.h>

using namespace std;


//void setupUnitRefs();

GtkWidget *makeLayout(void);

gboolean eventDraw(GtkWidget *widget, GdkEvent *event, gpointer data);
//void addButtons(GtkWidget *layout);
gint eventDelete(GtkWidget *widget,
        GdkEvent *event, gpointer data);
gint eventDestroy(GtkWidget *widget,
        GdkEvent *event, gpointer data);


// global variables

/*
// Forward declare a type (to be a struct).
typedef struct gamemap_type gamemap;
// Declare the struct
struct gamemap_type {
        int cell[MAP_WIDTH][MAP_HEIGHT]; // use for land or sea
        int cell[MAP_WIDTH][MAP_HEIGHT]; // use for land or sea
};
 */




GtkWidget *window;

cGrid oGrid;



int main(int argc, char *argv[]) {

    //cUnitRef oUnitRef[9]; 



    //setupUnitRefs();

    //GtkWidget *window;
    GtkWidget *layout; // a viewport with horizontal and vertical scroll bars


    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);
    gtk_signal_connect(GTK_OBJECT(window), "delete_event",
            GTK_SIGNAL_FUNC(eventDelete), NULL);
    gtk_signal_connect(GTK_OBJECT(window), "destroy",
            GTK_SIGNAL_FUNC(eventDestroy), NULL);

    layout = makeLayout();

    gtk_container_add(GTK_CONTAINER(window), layout);

    
    
    oGrid.generateMap(layout);


    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

void setupUnitRefs() {

    //println("debug: in setupunitrefs ");

    // UnitTypeId, UnitName, daysToProduce, strength, attackRange, caputuresCity, movesOnLand, movesOnWater, movesPerTurn, maxFuel
    /*
        oUnitRef[0] = new cUnitRef(0, "Tank",        4,  2, 1,  true,  true, false,  2, -1);
        oUnitRef[1] = new cUnitRef(1, "Fighter",     6,  1, 1, false,  true,  true, 20, 20);

        oUnitRef[2] = new cUnitRef(2, "Battleship", 20, 18, 4, false, false,  true,  3, -1);
        oUnitRef[3] = new cUnitRef(3, "Bomber",     25,  1, 1, false, true,  true, 10, 30);
        oUnitRef[4] = new cUnitRef(4, "Carrier",    10, 12, 1, false, false,  true,  3, -1);
        oUnitRef[5] = new cUnitRef(5, "Destroyer",   8,  3, 1, false, false,  true,  4, -1);
        oUnitRef[6] = new cUnitRef(6, "Transport",   8,  3, 1, false, false,  true,  3, -1);
        oUnitRef[7] = new cUnitRef(7, "Submarine",   8,  3, 1, false, false,  true,  3, -1);

        oUnitRef[8] = new cUnitRef(8, "Artillery",   4,  1, 4,  true,  true, false,  1, -1);
        oUnitRef[9] = new cUnitRef(9, "Helicopter",  8,  1, 1, false,  true,  true, 10, 10);
     */
    //oUnitRef[0].print();
    //oUnitRef[1].print();
}

gboolean eventDraw(GtkWidget *widget, GdkEvent *event, gpointer data) {

    oGrid.drawMapMargin(widget);
    oGrid.drawMap(widget);
    oGrid.drawUnits(widget);

    return (TRUE);
}

int GetRand(int min, int max) {
    static int Init = 0;
    int rc;

    if (Init == 0) {
        /*
         *  As Init is static, it will remember it's value between
         *  function calls.  We only want srand() run once, so this
         *  is a simple way to ensure that happens.
         */
        srand(time(NULL));
        Init = 1;
    }

    /*
     * Formula:  
     *    rand() % N   <- To get a number between 0 - N-1
     *    Then add the result to min, giving you 
     *    a random number between min - max.
     */
    rc = (rand() % (max - min + 1) + min);

    return (rc);
}

int RoundToInt(float f) {
    return (int) (f + 0.5f);
}


gint cGridCell::getX() {
    return x;
}

gint cGridCell::getY() {
    return y;
}


// ******************************************************
// WINDOW
// ******************************************************

GtkWidget *makeLayout(void) {

    GtkWidget *layout;
    GtkWidget *vscroll;
    GtkWidget *hscroll;
    GtkWidget *table;
    GtkAdjustment *horizAdj;
    GtkAdjustment *vertAdj;

    /*
    gtk_adjustment_new(
            gdouble value,
            gdouble lower,
            gdouble upper,
            gdouble step_increment,
            gdouble page_increment,
            gdouble page_size);
     */

    vertAdj = (GtkAdjustment *) gtk_adjustment_new(
            0.0,
            0.0,
            HEIGHT,
            UNIT_HEIGHT,
            10.0,
            20.0);
    horizAdj = (GtkAdjustment *) gtk_adjustment_new(
            0.0,
            0.0,
            WIDTH,
            UNIT_WIDTH,
            10.0,
            20.0);

    layout = gtk_layout_new(horizAdj, vertAdj);
    gtk_layout_set_size(GTK_LAYOUT(layout), WIDTH, HEIGHT);
    //addButtons(layout);

    GtkWidget *area; // a canvas to draw on
    area = gtk_drawing_area_new();
    gtk_widget_set_usize(area, WIDTH, HEIGHT);
    ////gtk_container_add (GTK_CONTAINER (layout), area);
    gtk_layout_put(GTK_LAYOUT(layout), area, 0, 0);
    //gtk_box_pack_start (GTK_BOX (box1), area, TRUE, TRUE, 0);

    g_signal_connect(GTK_OBJECT(area), "event", GTK_SIGNAL_FUNC(eventDraw), NULL);



    vscroll = gtk_vscrollbar_new(vertAdj);
    hscroll = gtk_hscrollbar_new(horizAdj);

    table = gtk_table_new(1, 1, FALSE);

    gtk_table_attach_defaults(GTK_TABLE(table), layout, 0, 1, 0, 1);
    gtk_table_attach(GTK_TABLE(table), vscroll, 1, 2, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
    gtk_table_attach(GTK_TABLE(table), hscroll, 0, 1, 1, 2, GTK_FILL, GTK_FILL, 0, 0);

    return (table);
}

gint eventDelete(GtkWidget *widget, GdkEvent *event, gpointer data) {
    return (FALSE);
}

gint eventDestroy(GtkWidget *widget, GdkEvent *event, gpointer data) {
    gtk_main_quit();
    return (0);
}


/*
void addButtons(GtkWidget *layout)
{
    gint i;
    gint j;
    GtkWidget *button;
    gchar label[20];

    for(i=100; i<1000; i += 100) {
        for(j=100; j<1000; j+= 50) {
            sprintf(label,"(%d,%d)",i,j);
            button = gtk_button_new_with_label(label);
            gtk_layout_put(GTK_LAYOUT(layout),button,i,j);
        }
    }
}
 */
