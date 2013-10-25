/* 
 * File:   city.h
 * Author: matthew
 *
 * Created on 24 October 2013, 21:00
 */

#ifndef CITY_H
#define	CITY_H

class cCity {
public:
    cCity(gint iCityPlayerId_, gint iCellX_, gint iCellY_, gint iCityIslandListId_);
    
    //virtual ~game_engine();
    
    //GString getLocation();

    gint getCellX();
    gint getCellY();

    gint getCityPlayerId();
    gint setCityPlayerId(gint iCityPlayerId_);

    gint setCityIslandListId(gint value_);
    gint getCityIslandListId();

    void printRowCol();
    
    gchar* getStatus();
    
    gboolean isNearby(gint iCellX_, gint iCellY_);
    
    gboolean isAt(gint, gint);
    
    gboolean isOccupied();

private:
    gint iCityPlayerId;
    gint iCityIslandListId;
    gint iCellX, iCellY;
    gint iProductionUnitTypeId;
    gchar* sProductionUnitTypeName;
    gint iProductionDaysLeft;
    gint iStrength;
};

//#include "unit_ref.h"
//extern cUnitRef oUnitRef[9]; 

#endif	/* CITY_H */

