/* 
 * File:   unit_ref.cpp
 * Author: matthew
 * 
 * Created on 24 October 2013, 20:28
 */

//#include <gtk/gtk.h>
//#include <iostream>
//#include "unit_ref.h"
//#include "includes.h"
////#include <string>
//
//
//using namespace std;


//gchar* cUnitRef::getUnitName(gint unitId_) {
//    return sUnitName[unitId_];
//}

/*
static void cUnitRef::print() {
    
    for(gint i=0; i<=NUMBER_OF_UNITS; i++)
        cout << " sUnitName=" << sUnitName[i] <<
                ", iDaysToProduce=" << iDaysToProduce[i] <<
                ", iStrength=" << iStrength[i] <<
                ", iAttackRange=" << iAttackRange[i] <<
                ", bCaputuresCity=" << bCaputuresCity[i] <<
                ", bMovesOnLand=" << bMovesOnLand[i] <<
                ", bMovesOnWater=" << bMovesOnWater[i] <<
                ", iMovesPerTurn=" << iMovesPerTurn[i] <<
                ", iMaxFuel=" << iMaxFuel[i]
                ;
}

static gint cUnitRef::calculateBombBlastRadius() {


    //println(" in unitref.calculateBombBlastRadius() ");

    
    //Initially, the Bombers have a radius of 0, and can thus only destroy one square. However, for Bombers started after day 50, the radius of the Bomber goes up to 1, meaning that the same bomb can now destroy 9 squares and everything in them. After day 100, Bombers will have radius 2, and will destroy a total of 25 squares. 
     

    //println("debug#1 ");
    gint result = 0;
    //println("debug#2 ");
    gint iTargetDay = 0;
    //println("debug#3 ");

    iTargetDay = iTargetDay + 20 + 50;

    /-*
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

 *-/

    //println(" result="+result);

    return result;
}
 */