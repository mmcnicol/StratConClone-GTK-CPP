/* 
 * File:   unit_ref.cpp
 * Author: matthew
 * 
 * Created on 24 October 2013, 20:28
 */

#include <gtk/gtk.h>
#include "unit_ref.h"
#include <iostream>
#include "includes.h"
//#include <string>


using namespace std;


//cUnitRef::cUnitRef() {
//}


cUnitRef::cUnitRef(gint iUnitTypeId_, gchar* sUnitName_, gint iDaysToProduce_, gint iStrength_, gint iAttackRange_, gboolean bCaputuresCity_, gboolean bMovesOnLand_, gboolean bMovesOnWater_, gint iMovesPerTurn_, gint iMaxFuel_) {

        iUnitTypeId = iUnitTypeId_;
        sUnitName = sUnitName_;
        iDaysToProduce = iDaysToProduce_;
        iStrength = iStrength_;
        iAttackRange = iAttackRange_;
        bCaputuresCity = bCaputuresCity_;
        bMovesOnLand = bMovesOnLand_;
        bMovesOnWater = bMovesOnWater_;
        iMovesPerTurn = iMovesPerTurn_;
        iMaxFuel = iMaxFuel_; 
    }

cUnitRef* oUnitRef[9]; 
//cUnitRef oUnitRef(); 
/*
   oUnitRef[0] = new cUnitRef(0, "Tank",        4,  2, 1,  TRUE,  TRUE, FALSE,  2, -1);
    oUnitRef[1] = new cUnitRef(1, "Fighter",     6,  1, 1, FALSE,  TRUE,  TRUE, 20, 20);

    oUnitRef[2] = new cUnitRef(2, "Battleship", 20, 18, 4, FALSE, FALSE,  TRUE,  3, -1);
    oUnitRef[3] = new cUnitRef(3, "Bomber",     25,  1, 1, FALSE, TRUE,  TRUE, 10, 30);
    oUnitRef[4] = new cUnitRef(4, "Carrier",    10, 12, 1, FALSE, FALSE,  TRUE,  3, -1);
    oUnitRef[5] = new cUnitRef(5, "Destroyer",   8,  3, 1, FALSE, FALSE,  TRUE,  4, -1);
    oUnitRef[6] = new cUnitRef(6, "Transport",   8,  3, 1, FALSE, FALSE,  TRUE,  3, -1);
    oUnitRef[7] = new cUnitRef(7, "Submarine",   8,  3, 1, FALSE, FALSE,  TRUE,  3, -1);

    oUnitRef[8] = new cUnitRef(8, "Artillery",   4,  1, 4,  TRUE,  TRUE, FALSE,  1, -1);
    oUnitRef[9] = new cUnitRef(9, "Helicopter",  8,  1, 1, FALSE,  TRUE,  TRUE, 10, 10);
*/

    



void cUnitRef::print() {
    cout << "iUnitTypeId=" << iUnitTypeId << 
        ", sUnitName=" << sUnitName << 
        ", iDaysToProduce=" << iDaysToProduce << 
        ", iStrength=" << iStrength << 
        ", iAttackRange=" << iAttackRange <<
        ", bCaputuresCity=" << bCaputuresCity <<
        ", bMovesOnLand=" << bMovesOnLand <<
        ", bMovesOnWater=" << bMovesOnWater <<
        ", iMovesPerTurn=" << iMovesPerTurn <<
        ", iMaxFuel=" << iMaxFuel
        ;
}

gint cUnitRef::getUnitTypeId() { return iUnitTypeId; }
gchar* cUnitRef::getUnitName() { return sUnitName; }
gint cUnitRef::getDaysToProduce() { return iDaysToProduce; }
gint cUnitRef::getStrength() { return iStrength; }
gint cUnitRef::getAttackRange() { return iAttackRange; }
gboolean cUnitRef::getCaputuresCity() { return bCaputuresCity; }
gboolean cUnitRef::getMovesOnLand() { return bMovesOnLand; }
gboolean cUnitRef::getMovesOnWater() { return bMovesOnWater; }
gint cUnitRef::getMovesPerTurn() { return iMovesPerTurn; }
gint cUnitRef::getMaxFuel() { return iMaxFuel; }

gboolean cUnitRef::canFly() { 
    if( iMaxFuel==-1) return false; 
    else return true; 
}
	
	
int calculateBombBlastRadius() {


    //println(" in unitref.calculateBombBlastRadius() ");

    /*
    Initially, the Bombers have a radius of 0, and can thus only destroy one square. However, for Bombers started after day 50, the radius of the Bomber goes up to 1, meaning that the same bomb can now destroy 9 squares and everything in them. After day 100, Bombers will have radius 2, and will destroy a total of 25 squares. 
    */

    //println("debug#1 ");
    gint result=0;
    //println("debug#2 ");
    gint iTargetDay=0;
    //println("debug#3 ");

    iTargetDay = iTargetDay + 20 + 50;
    
    /*
    //println("debug#4 ");
    if (oGameEngine.getDayNumber() > iTargetDay ) result++;
    //println("debug#5 ");

    iTargetDay = iTargetDay + 5 + 50;
    //println("debug#6 ");
    if (oGameEngine.getDayNumber() > iTargetDay ) result++;
    //println("debug#7 ");

    iTargetDay = iTargetDay + 5 + 50;
    if (oGameEngine.getDayNumber() > iTargetDay ) result++;

    iTargetDay = iTargetDay + 5 + 50;
    if (oGameEngine.getDayNumber() > iTargetDay ) result++;

    iTargetDay = iTargetDay + 5 + 50;
    if (oGameEngine.getDayNumber() > iTargetDay ) result++;

    iTargetDay = iTargetDay + 5 + 50;
    if (oGameEngine.getDayNumber() > iTargetDay ) result++;

    iTargetDay = iTargetDay + 5 + 50;
    if (oGameEngine.getDayNumber() > iTargetDay ) result++;

    iTargetDay = iTargetDay + 5 + 50;
    if (oGameEngine.getDayNumber() > iTargetDay ) result++;

    */

    //println(" result="+result);

    return result;
}
