/** pixmap.c **/
#include <gtk/gtk.h>
#include "pieces.h"
//#include <gnome.h>

#include "../img/pieces.xpm"
#include "../img/pieces_inverted.xpm"

/***********************************************************
function: drawPiece()

parameter: GtkWidget *widget,  
parameter: unit_type unit,          // a typedef enum, defined in pieces.h
parameter: gint x,                  // coordinates in pixels (top left is 0,0)
parameter: gint y,
parameter: gint unit_count          // if greater than 0, show number in top left

returns: gboolean
 */

gboolean drawPiece(GtkWidget *widget, unit_type unit, player_type player, gint unit_count, gint x, gint y) {

    GdkBitmap *mask;
    GdkPixmap *pixmap;
    GtkStyle *style;
    GdkFont *font;

    //font = gdk_font_load("10x20");
    //font = gdk_font_load ("-misc-fixed-medium-r-*-*-*-140-*-*-*-*-*-*");
    //font = gdk_font_load ("-*-helvetica-medium-r-normal--*-60-*-*-*-*-*-*");
    font = gdk_font_load("-misc-fixed-medium-r-*-*-*-60-*-*-*-*-*-*");
    //font = gtk_style_get_font(widget->style);

    /*    static GdkPoint points[] = {
            { 210, 253 },
            { 220, 245 },
            { 220, 252 },
            { 295, 252 },
            { 295, 254 },
            { 220, 254 },
            { 220, 260 },
        };
     */
    style = gtk_widget_get_style(widget);

    if (player == human) {
        pixmap = gdk_pixmap_create_from_xpm_d(widget->window,
                &mask, &style->bg[GTK_STATE_NORMAL],
                (gchar **) pieces_xpm);
    } else {
        pixmap = gdk_pixmap_create_from_xpm_d(widget->window,
                &mask, &style->bg[GTK_STATE_NORMAL],
                (gchar **) pieces_inverted_xpm);
    }

    /*
            // use this to draw a simple image
            gdk_draw_pixmap(widget->window,
                widget->style->black_gc,
                pixmap,
                0,0,
                0,0,
                386,103);
     */

    switch (unit) {

            // column 1

        case army:
            gdk_draw_pixmap(widget->window, widget->style->black_gc, pixmap,
                    6, 23,
                    x, y,
                    UNIT_WIDTH, UNIT_HEIGHT);
            break;

            // column 2

        case destroyer:
            gdk_draw_pixmap(widget->window, widget->style->black_gc, pixmap,
                    96, 23,
                    x, y,
                    UNIT_WIDTH, UNIT_HEIGHT);
            break;

        case submarine:
            gdk_draw_pixmap(widget->window, widget->style->black_gc, pixmap,
                    97, 41,
                    x, y,
                    UNIT_WIDTH, UNIT_HEIGHT);
            break;

        case transport:
            gdk_draw_pixmap(widget->window, widget->style->black_gc, pixmap,
                    98, 58,
                    x, y,
                    UNIT_WIDTH, UNIT_HEIGHT);
            break;

        case carrier:
            gdk_draw_pixmap(widget->window, widget->style->black_gc, pixmap,
                    97, 76,
                    x, y,
                    UNIT_WIDTH, UNIT_HEIGHT);
            break;

            // column 3

        case battleship:
            gdk_draw_pixmap(widget->window, widget->style->black_gc, pixmap,
                    196, 6,
                    x, y,
                    UNIT_WIDTH, UNIT_HEIGHT);
            break;

        case fighter:
            gdk_draw_pixmap(widget->window, widget->style->black_gc, pixmap,
                    196, 25,
                    x, y,
                    UNIT_WIDTH, UNIT_HEIGHT);
            break;

        case bomber:
            gdk_draw_pixmap(widget->window, widget->style->black_gc, pixmap,
                    198, 63,
                    x, y,
                    UNIT_WIDTH, UNIT_HEIGHT);
            break;

            // column 4

        case city:
            gdk_draw_pixmap(widget->window, widget->style->black_gc, pixmap,
                    294, 24,
                    x, y,
                    UNIT_WIDTH, UNIT_HEIGHT);
            break;

        default:
            g_print("debug: in drawPiece() unit not defined\n");
    }


    if (unit_count > 0) {

        // convert integer value to string
        char temp_string[3];
        sprintf(temp_string, "%d", unit_count);

        // a crude calculation of string width & height
        gint font_width = 6;
        gint font_height = 6;
        if (unit_count > 9) font_width = 10;
        if (unit_count > 99) font_width = 15;


        /* gdk_draw_rectangle (GdkDrawable *drawable, GdkGC *gc, gint filled, 
                gint x, gint y, gint width, gint height);
         */

        // clear string background
        if (player == human) {
            gdk_draw_rectangle(widget->window, widget->style->white_gc, 1,
                    x, y, font_width, font_height);
        } else {
            gdk_draw_rectangle(widget->window, widget->style->black_gc, 1,
                    x, y, font_width, font_height);
        }

        // draw string
        if (player == human) {
            gdk_draw_string(widget->window, font, widget->style->black_gc,
                    x + 1, y + 5, temp_string);
        } else {
            gdk_draw_string(widget->window, font, widget->style->white_gc,
                    x + 1, y + 5, temp_string);
        }


    }


    /*
        gdk_draw_pixmap(widget->window,
                widget->style->black_gc,
                pixmap,
                70,60,
                210,50,
                90,50);
        gdk_draw_string(widget->window,
                font,
                widget->style->white_gc,
                240,75,
                "Beak");
            
        gdk_draw_pixmap(widget->window,
                widget->style->black_gc,
                pixmap,
                0,200,
                350,105,
                100,100);
        gdk_draw_string(widget->window,
                font,
                widget->style->black_gc,
                350,210,
                "Right");

        gdk_draw_string(widget->window,
                font,
                widget->style->black_gc,
                300,260,
                "Left");
        gdk_draw_polygon(widget->window,
                widget->style->black_gc,
                TRUE,
                points,
                sizeof(points) / sizeof(GdkPoint));
     */
    gdk_pixmap_unref(pixmap);
    gdk_font_unref(font);
    return (TRUE);
}

