/* 
 * File:   includes.h
 * Author: matthew
 *
 * Created on 24 October 2013, 23:40
 */

#ifndef INCLUDES_H
#define	INCLUDES_H


#define WIDTH UNIT_WIDTH*81
#define HEIGHT UNIT_HEIGHT*81

#define MAP_WIDTH 81
#define MAP_HEIGHT 81

#define MAP_OFFSET_X 0
#define MAP_OFFSET_Y 0

#define DEBUG_ISLANDLISTID TRUE

//#include "unit_ref.h"
//extern cUnitRef oUnitRef[9]; 

gint GetRand(gint min, gint max);
gint RoundToInt(gfloat f);




struct cell_class {
    gboolean isLand;
    gint islandId;
    gboolean isFogOfWar;
};





class cGridCell {
    int x, y;
public:

    cGridCell(gint _x, gint _y) {
        x = _x;
        y = _y;
    }
    gint getX(void);
    gint getY(void);
};




#endif	/* INCLUDES_H */

