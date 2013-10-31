/* 
 * File:   unit_ref.h
 * Author: matthew
 *
 * Created on 24 October 2013, 21:26
 */

#ifndef UNIT_REF_H
#define	UNIT_REF_H


const gint NUMBER_OF_UNITS = 10;

/*
class cUnitRef {
    //    cUnitRef() {
    //        defineUnit(0, "Tank", 4, 2, 1, TRUE, TRUE, FALSE, 2, -1, FALSE);
    //        defineUnit(1, "Fighter", 6, 1, 1, FALSE, TRUE, TRUE, 20, 20, TRUE);
    //
    //        defineUnit(2, "Battleship", 20, 18, 4, FALSE, FALSE, TRUE, 3, -1, FALSE);
    //        defineUnit(3, "Bomber", 25, 1, 1, FALSE, TRUE, TRUE, 10, 30, TRUE);
    //        defineUnit(4, "Carrier", 10, 12, 1, FALSE, FALSE, TRUE, 3, -1, FALSE);
    //        defineUnit(5, "Destroyer", 8, 3, 1, FALSE, FALSE, TRUE, 4, -1, FALSE);
    //        defineUnit(6, "Transport", 8, 3, 1, FALSE, FALSE, TRUE, 3, -1, FALSE);
    //        defineUnit(7, "Submarine", 8, 3, 1, FALSE, FALSE, TRUE, 3, -1, FALSE);
    //
    //        defineUnit(8, "Artillery", 4, 1, 4, TRUE, TRUE, FALSE, 1, -1, FALSE);
    //        defineUnit(9, "Helicopter", 8, 1, 1, FALSE, TRUE, TRUE, 10, 10, TRUE);
    //    }



public:

    //gchar* sUnitName[NUMBER_OF_UNITS];
    gint iDaysToProduce[NUMBER_OF_UNITS];
    gint iStrength[NUMBER_OF_UNITS];
    gint iAttackRange[NUMBER_OF_UNITS];
    gboolean bCaputuresCity[NUMBER_OF_UNITS];
    gboolean bMovesOnLand[NUMBER_OF_UNITS];
    gboolean bMovesOnWater[NUMBER_OF_UNITS];
    gint iMovesPerTurn[NUMBER_OF_UNITS];
    gint iMaxFuel[NUMBER_OF_UNITS]; // -1 = N/A
    gboolean bCanFly[NUMBER_OF_UNITS];

    static void defineUnit(gint iUnitTypeId_, gchar* sUnitName_, gint iDaysToProduce_, gint iStrength_, gint iAttackRange_, gboolean bCaputuresCity_, gboolean bMovesOnLand_, gboolean bMovesOnWater_, gint iMovesPerTurn_, gint iMaxFuel_, gboolean bCanFly_) {

        //sUnitName[iUnitTypeId_] = sUnitName_;
        iDaysToProduce[iUnitTypeId_] = iDaysToProduce_;
        iStrength[iUnitTypeId_] = iStrength_;
        iAttackRange[iUnitTypeId_] = iAttackRange_;
        bCaputuresCity[iUnitTypeId_] = bCaputuresCity_;
        bMovesOnLand[iUnitTypeId_] = bMovesOnLand_;
        bMovesOnWater[iUnitTypeId_] = bMovesOnWater_;
        iMovesPerTurn[iUnitTypeId_] = iMovesPerTurn_;
        iMaxFuel[iUnitTypeId_] = iMaxFuel_;
        bCanFly[iUnitTypeId_] = bCanFly_;
    }

    //void defineUnit(gint iUnitTypeId_, gchar* sUnitName_, gint iDaysToProduce_, gint iStrength_, gint iAttackRange_, gboolean bCaputuresCity_, gboolean bMovesOnLand_, gboolean bMovesOnWater_, gint iMovesPerTurn_, gint iMaxFuel_, gboolean bCanFly);

    //virtual ~cUnitRef();

    //static gchar* getUnitName(gint unitId_);

    //    static gint getDaysToProduce(gint unitId_) {
    //        return iDaysToProduce[unitId_];
    //    }

    static gint getStrength(gint unitId_) {
        return iStrength[unitId_];
    }

    static gint getAttackRange(gint unitId_) {
        return iAttackRange[unitId_];
    }

    static gboolean getCaputuresCity(gint unitId_) {
        return bCaputuresCity[unitId_];
    }

    static gboolean getMovesOnLand(gint unitId_) {
        return bMovesOnLand[unitId_];
    }

    static gboolean getMovesOnWater(gint unitId_) {
        return bMovesOnWater[unitId_];
    }

    static gint getMovesPerTurn(gint unitId_) {
        return iMovesPerTurn[unitId_];
    }

    static gint getMaxFuel(gint unitId_) {
        return iMaxFuel[unitId_];
    }

    static gboolean canFly(gint unitId_) {
        return iMaxFuel[unitId_];
    }

    //static void print();

    //static gint calculateBombBlastRadius();

};
*/


#endif	/* UNIT_REF_H */

