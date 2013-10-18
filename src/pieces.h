/* 
 * File:   pieces.h
 * Author: matthew
 *
 * Created on 18 October 2013, 01:50
 */

#ifndef PIECES_H
#define	PIECES_H

#define UNIT_WIDTH 18
#define UNIT_HEIGHT 14

typedef enum {
	army,
	destroyer,
	submarine,
	transport,
	carrier,
	battleship,
	fighter,
	bomber,
	city
} unit_type;

typedef enum {
	human, computer
} player_type;

/*
typedef enum {
	false, true
} bool_type;
*/


gboolean drawPiece(GtkWidget *widget, unit_type, player_type, gint, gint, gint);


#endif	/* PIECES_H */

