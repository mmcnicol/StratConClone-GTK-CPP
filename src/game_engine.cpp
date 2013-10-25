/* 
 * File:   game_engine.cpp
 * Author: matthew
 * 
 * Created on 24 October 2013, 20:28
 */

#include <gtk/gtk.h>
#include "game_engine.h"


cGameEngine::cGameEngine() {
    dayNumber = 1;
    selectedUnitListId = -1;
    selectedCityListId = -1;
    iCurrentPlayerId = -1;
    iCommand = -1;
    iCurrentlyProcessingPlayerTurn = FALSE;
}


int cGameEngine::getDayNumber() {
    return dayNumber;
}


//bool isIdle() { return bIdle; }


void cGameEngine::setSelectedUnitListId(gint value_) {
    selectedUnitListId = value_;
}


gint cGameEngine::getSelectedUnitListId() {
    return selectedUnitListId;
}


void cGameEngine::setSelectedCityListId(gint value_) {
    selectedCityListId = value_;
}


gint cGameEngine::getSelectedCityListId() {
    return selectedCityListId;
}


gint cGameEngine::getCurrentPlayerId() {
    return iCurrentPlayerId;
}


void cGameEngine::setCurrentlyProcessingPlayerTurn(gboolean value_) {
    iCurrentlyProcessingPlayerTurn = value_;
}


bool cGameEngine::getCurrentlyProcessingPlayerTurn() {
    return iCurrentlyProcessingPlayerTurn;
}


void cGameEngine::setCommand(gint value_) {
    iCommand = value_;
}


gint cGameEngine::getCommand() {
    return iCommand;
}


void cGameEngine::doPlayerMove() {

    /*
     
    //println("GameEngine.loop() begin");

    if ( getCurrentlyProcessingPlayerTurn()==false ) {

        setCurrentlyProcessingPlayerTurn(true);

        // payer 1, human, moves first
        if( oUnitList.getCountUnitsWithMovesLeftToday(1)!=0 ) {

            //println("in game engine.doPlayerMove(), player 1 has units to move");

            iCurrentPlayerId=1;
            oPanel2.show();
            //oGameEngine.setCommand(-1);

            if ( oPlayer1.getIsAI() ) {
                //println("moveNextUnitWithMovesLeftToday...");
                //oUnitList.highlightNextUnitWithMovesLeftToday(1);

                oUnitList.moveNextUnitWithMovesLeftToday(1);
            } else {
                // if (oAnimateAttack.getCanAttackUnitListId()==-1) {
                //if ( oAnimate.getUnitListId()==-1 ) oUnitList.highlightNextUnitWithMovesLeftToday(1);
                oUnitList.highlightNextUnitWithMovesLeftToday(1);
                //oViewport.draw();
            }


        // payer 2, computer, moves second		
        } else if( oUnitList.getCountUnitsWithMovesLeftToday(2)!=0 ) {


            //println("in loop, player 2 (computer) has units to move");

            iCurrentPlayerId=2;
            oPanel2.show();
            oPanelGameMessageLine.clear(70);
            oAnimate.clear();

            oUnitList.highlightNextUnitWithMovesLeftToday(2);

            //println("debug#1");
            if ( oPlayer2.getIsAI() ) {
                //println("moveNextUnitWithMovesLeftToday...");
                oUnitList.moveNextUnitWithMovesLeftToday(2);
            }


        } else {

            // if payer 1 and player 2 have no units to be moved, progress to next day
            //println("debug 7: GameState="+GameState);
            nextDay();

            checkforGameOver();

        }

        oCityList.updateSelectedCityPanelInformation( getSelectedCityListId() );
    } else {
        println("debug: in GameEngine.doPlayerMove() skipping because getCurrentlyProcessingPlayerTurn()==true");
    }

    setCurrentlyProcessingPlayerTurn(false);


    // GameState code 4=play
    if ( GameState==4 ) {

            oPanelMap.show();
            if (debugShowPlayer2Viewport) oPanelMapPlayer2.show();

            //oPanelCityList.show(); // FISH
            //oPanelIslandList.show(); // FISH

            oPanelPlayer1UnitCounts.show();
            if (debugShowPlayer2Viewport) oPanelPlayer2UnitCounts.show();

    }

    //bIdle=true;
     */
}


void cGameEngine::nextDay() {
    /*
     dayNumber++;
    //println("Day " + dayNumber);
    println("");

    oUnitList.resetMovesLeftToday();
    oCityList.manageProduction();

    //background(0);

    //oCityList.Draw();
    //if ( getCurrentPlayerId() > 0 ) {
            oViewport.draw();
            if (debugShowPlayer2Viewport) oViewportPlayer2.draw();
    //}

    //oPanelCityList.show();
    //oPanelIslandList.show();

    oIslandList.updateIslandStatus();
    //oPanelCityList.show();

    //oPanelPlayer1UnitCounts.show();
    //oPanelPlayer2UnitCounts.show();
    */
}


void cGameEngine::checkforGameOver() {
    /*

    //should player 2 surrender?
    //println("should player 2 surrender?");

    if ( getDayNumber()>=iMinDayNumber ) {

        if ( oUnitList.getCountOfPlayerUnits(2)<=iMinUnitNumber && oCityList.getCountPlayerCity(2)<=iMinCityNumber ) {

            if ( oPlayer1.getIsAI() ) {
                gameOver(1);			
            } else {
                //println("display DialogueSurrender...");
                oDialogueSurrender.show();
                //println("displayed DialogueSurrender.");
            }

        } else if ( oUnitList.getCountOfPlayerUnits(1)<=iMinUnitNumber && oCityList.getCountPlayerCity(1)<=iMinCityNumber ) {
            gameOver(2);

        }
    }
    */
}


void cGameEngine::gameOver(gint iPlayerIdWinner_) {
    /*
    GameState=99;	
    if (iPlayerIdWinner_==1) {
        println("");
        println("General, I surrender.");
        println("");
    }
    println("Player "+iPlayerIdWinner_+" has won!");
    println("Thank you for playing StratConClone!");
    println("");	
    */
}
