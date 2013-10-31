/* 
 * File:   city.cpp
 * Author: matthew
 * 
 * Created on 24 October 2013, 20:28
 */

#include <gtk/gtk.h>
#include <iostream>
#include <stdlib.h>     /* abs */
#include "city.h"
#include "unit_ref.h"
#include "includes.h"

using namespace std;

cCity::cCity(gint iCityPlayerId_, gint iCellX_, gint iCellY_, gint iCityIslandListId_) {

    //if (debugCityAdd) println("   cCity constructor for intCityPlayerId_=" + intCityPlayerId_+", iCityIslandListId_="+iCityIslandListId_);

    iCityPlayerId=iCityPlayerId_;
    setCityIslandListId(iCityIslandListId_);
    iCellX=iCellX_;
    iCellY=iCellY_;

    iStrength=1; //int(random(1,3));

    //if( intCityPlayerId_==1 ) {
        //println("cCity constructor for intCityPlayerId_=" + intCityPlayerId_ +" strength="+strength);
    //}

    if( iCityPlayerId_ != -1 ) {
        //count << "is human or computer city so build a tank";
        // game rule: default initial production to Tank
        iProductionUnitTypeId= 0; 
        //iProductionDaysLeft = cUnitRef::getDaysToProduce(0);
        iProductionDaysLeft = 4;
        //sProductionUnitTypeName = cUnitRef::getUnitName(0);
        //println("productionUnitTypeId=" + productionUnitTypeId + ", productionDaysLeft=" + productionDaysLeft);

        //oIslandList.updateIslandPlayerCityCount(getCityIslandListId(), -1, intCityPlayerId_);

    } else { 
        //println("city is unoccupied so build nothing");
        // game rule: empty city does not produce anything
        iProductionUnitTypeId= -1; 
        iProductionDaysLeft = -1;
        //sProductionUnitTypeName = "N/A";
        //println("productionUnitTypeId=" + productionUnitTypeId + ", productionDaysLeft=" + productionDaysLeft);

        //oIslandList.increaseUnoccupiedCityCount( getCityIslandListId() );
    }
 
}


//GString cCity::getLocation() { return nf(iCellX,3)+","+nf(iCellY,3); }

gint cCity::getCellX() { return iCellX; }
gint cCity::getCellY() { return iCellY; }

gint cCity::getCityPlayerId() { return iCityPlayerId; }
gint cCity::setCityPlayerId(gint iCityPlayerId_) { iCityPlayerId=iCityPlayerId_; }

gint cCity::setCityIslandListId(gint value_) { iCityIslandListId=value_; }
gint cCity::getCityIslandListId() { return iCityIslandListId; }


void cCity::printRowCol() {
    cout << "city at row=" << iCellX << ", col=" << iCellY;
}


gchar* cCity::getStatus() {

    gchar* sStatus="Unoccupied";

    switch( getCityPlayerId() ) {
        case 1: 
            sStatus="player 1";
            break;
        case 2: 
            sStatus="player 2";
            break;
    }

    return sStatus;
}


gboolean cCity::isNearby(gint iCellX_, gint iCellY_) {
    if ( abs(iCellX_ - iCellX)<=2 && abs(iCellY_ - iCellY)<=2 ) return true;
    else return false; 
}


gboolean cCity::isAt(gint cellRow_, gint cellCol_) {
    if( iCellX==cellRow_ && iCellY==cellCol_ ) return true;
    else return false;
}


gboolean cCity::isOccupied() {
    if( iCityPlayerId==-1 ) return false;
    else return true;
}

