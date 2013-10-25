/* 
 * File:   unit_ref.h
 * Author: matthew
 *
 * Created on 24 October 2013, 21:26
 */

#ifndef UNIT_REF_H
#define	UNIT_REF_H

class cUnitRef {
public:
    //cUnitRef();
    cUnitRef(gint iUnitTypeId_, gchar* sUnitName_, gint iDaysToProduce_, gint iStrength_, gint iAttackRange_, gboolean bCaputuresCity_, gboolean bMovesOnLand_, gboolean bMovesOnWater_, gint iMovesPerTurn_, gint iMaxFuel_);
    
    /*
    cUnitRef(gint iUnitTypeId_, gchar* sUnitName_, gint iDaysToProduce_, gint iStrength_, gint iAttackRange_, gboolean bCaputuresCity_, gboolean bMovesOnLand_, gboolean bMovesOnWater_, gint iMovesPerTurn_, gint iMaxFuel_) {

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
    */
    
    //virtual ~cUnitRef();
    
    //GString getLocation();

    void print();
    
    gint getUnitTypeId();
    gchar* getUnitName();
    gint getDaysToProduce();
    gint getStrength();
    gint getAttackRange();
    gboolean getCaputuresCity();
    gboolean getMovesOnLand();
    gboolean getMovesOnWater();
    gint getMovesPerTurn();
    gint getMaxFuel();

    gboolean canFly();
    
    
private:
	gint iUnitTypeId;
	gchar* sUnitName;
	gint iDaysToProduce;
	gint iStrength;
	gint iAttackRange;
	gboolean bCaputuresCity;
	gboolean bMovesOnLand;
	gboolean bMovesOnWater;
	gint iMovesPerTurn;
	gint iMaxFuel; // -1 = N/A
};


#endif	/* UNIT_REF_H */

