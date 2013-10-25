/* 
 * File:   game_engine.h
 * Author: matthew
 *
 * Created on 24 October 2013, 20:28
 */

#ifndef GAME_ENGINE_H
#define	GAME_ENGINE_H

class cGameEngine {
public:
    cGameEngine();
    
    //virtual ~game_engine();
    
    gint getDayNumber();

    //bool isIdle() { return bIdle; }

    void setSelectedUnitListId(gint value_);

    gint getSelectedUnitListId();

    void setSelectedCityListId(gint value_);

    gint getSelectedCityListId();

    gint getCurrentPlayerId();

    void setCurrentlyProcessingPlayerTurn(gboolean value_);

    bool getCurrentlyProcessingPlayerTurn();

    void setCommand(gint value_);

    gint getCommand();
    
    void doPlayerMove();
    
    void nextDay();
    
    void checkforGameOver();
    
    void gameOver(gint iPlayerIdWinner_);

private:
    gint dayNumber;
    gint selectedUnitListId;
    gint selectedCityListId;
    gint iCurrentPlayerId;
    gint iCommand; // human player command e.g. (1) wake or (2) move stack
    gboolean iCurrentlyProcessingPlayerTurn;

    gint iMinDayNumber=10;
    gint iMinUnitNumber=10;
    gint iMinCityNumber=0;
};

#endif	/* GAME_ENGINE_H */



#ifdef FALSE
#undef FALSE
#endif
#define FALSE 0

#ifdef TRUE
#undef TRUE
#endif
#define TRUE  1

typedef int BOOL;

