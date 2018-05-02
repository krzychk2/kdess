/*
 * Copyright (c) 2018, <copyright holder> <email>
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY <copyright holder> <email> ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <copyright holder> <email> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef KDESS_H
#define KDESS_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QGridLayout>
#include <QVector>
#include <QString>
#include <QSettings>
#include <QUrl>

#define MAX_PLAYERS 64

class KDESS : public QWidget {
 Q_OBJECT
 
public:
    KDESS(QString iniFileName, QWidget *parent = 0);
    
private:
/*
 * 1 okno
 * 4 okna - obszar 2x2
 * 6 okien - obszar 3x3 przy czym 4 okna są sklejone w jedno
 * 7 okien - obszar 2x2 przy czym jedno okno jest podzielone 2x2
 * 8 okien - obszar 4x4 przy czym 9 okien jest sklejonych w jedno
 * 9 okien - obszar 3x3
 * 13 okien - obszar 4x4 przy czym 4 okna w środką są sklejone w jedno
 * 16 okien - obszar 4x4
 * 20 okien - obszar 6x6 przy czym 2 obszary 3x3 są sklejone w dwa okna (jedno okno 3x3)
 * 25 okien - obszar 5x5
 * 36 okien - obszar 6x6
 * 49 okien - obszar 7x7
 * 64 okna - obszar 8x8
 */    
    void OneScreenLayout();
    void FourScreensLayout();
    void SixScreensLayout();
    void SevenScreensLayout();
    void EightScreensLayout();
    void NineScreensLayout();
    void ThirteenScreensLayout();
    void SixteenScreensLayout();
    void TwentyScreensLayout();
    void TwentyFiveScreensLayout();
    void ThirtySixScreensLayout();
    void FourtyNineScreensLayout();
    void SixtyFourScreensLayout();

    /*
     * Inicjalizacja player-ów
     * 
     */
    void initPlayers(int noOfPlayers);
    
private:
    
    enum { MaxPlayers = 64 };
    
    QMediaPlayer *players[MaxPlayers];
    QVideoWidget *videos[MaxPlayers];
    QString addresses[MaxPlayers]; 

    
};

#endif
