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

#include "kdess.h"

KDESS::KDESS(QString iniFileName, QWidget* parent) : QWidget(parent)
{

    QSettings settings(iniFileName, QSettings::IniFormat);
        
    int noOfScreens = settings.value("Screen/size", 4).toInt();
    
    for(int i=0; i<MaxPlayers; i++){
        QString iniTmp;
        if(i<8)
            iniTmp="Players/URL0"+QString::number(i+1);
        else
            iniTmp="Players/URL"+QString::number(i);
        addresses[i] = settings.value(iniTmp, "").toString();      
    }
    /*
     * Init media players and video outputs
     */
     
    //By default - 4 screen layout
    switch(noOfScreens){
        case 1:
            initPlayers(noOfScreens);
            OneScreenLayout();
            break;
        case 4:
            initPlayers(noOfScreens);
            FourScreensLayout();
            break;
        case 6:
            initPlayers(noOfScreens);
            SixScreensLayout();
            break;
        case 7:
            initPlayers(noOfScreens);
            SevenScreensLayout();
            break;
        case 8:
            initPlayers(noOfScreens);
            EightScreensLayout();
            break;
        case 9:
            initPlayers(noOfScreens);
            NineScreensLayout();
            break;
        case 13:
            initPlayers(noOfScreens);
            ThirteenScreensLayout();
            break;
        case 16:
            initPlayers(noOfScreens);
            SixteenScreensLayout();
            break;
        case 20:
            initPlayers(noOfScreens);
            TwentyScreensLayout();
            break;
        case 25:
            initPlayers(noOfScreens);
            TwentyFiveScreensLayout();
            break;
        case 36:
            initPlayers(noOfScreens);
            ThirtySixScreensLayout();
            break;
        case 49:
            initPlayers(noOfScreens);
            FourtyNineScreensLayout();
            break;
        case 64:
            initPlayers(noOfScreens);
            SixtyFourScreensLayout();
            break;
        default: 
            initPlayers(4);
            FourScreensLayout();
    }
    
}

void KDESS::initPlayers(int noOfPlayers){
    for (int i=0; i<noOfPlayers; i++) {
        players[i] = new QMediaPlayer;
        players[i]->setMedia(QUrl(addresses[i]));

        videos[i] = new QVideoWidget;
        videos[i]->setAspectRatioMode(Qt::IgnoreAspectRatio);
        //videos[i]->show();

        players[i]->setVideoOutput(videos[i]);
        players[i]->play();
    }
    
}

void KDESS::OneScreenLayout()
{
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSpacing(0);
    mainLayout->addWidget(videos[0], 0, 0);
    setLayout(mainLayout);
    
}

void KDESS::FourScreensLayout()
{
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSpacing(0);

    /*
     * 2x2
     */
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++)
                mainLayout->addWidget(videos[(i*2)+j], i, j);
    }

    setLayout(mainLayout);

}

void KDESS::SixScreensLayout(){

    QGridLayout *mainLayout = new QGridLayout;

    /*
     * 3x3
     */
 
    mainLayout->setSpacing(0);
    mainLayout->addWidget(videos[0], 0, 0, 2, 2);  
    mainLayout->addWidget(videos[1], 0, 2);
    mainLayout->addWidget(videos[2], 1, 2);
    mainLayout->addWidget(videos[3], 2, 0);
    mainLayout->addWidget(videos[4], 2, 1);
    mainLayout->addWidget(videos[5], 2, 2);

    setLayout(mainLayout);
    
}

void KDESS::SevenScreensLayout(){
    QGridLayout *mainLayout = new QGridLayout;

    /*
     * 4x4
     */
    mainLayout->setSpacing(0);

    mainLayout->addWidget(videos[0], 0, 0);
    mainLayout->addWidget(videos[1], 0, 1);
    mainLayout->addWidget(videos[2], 1, 0);
    
    QGridLayout *smallLayout = new QGridLayout;
    
    smallLayout->setSpacing(0);
    smallLayout->addWidget(videos[3], 0, 0);
    smallLayout->addWidget(videos[4], 0, 1);
    smallLayout->addWidget(videos[5], 1, 0);
    smallLayout->addWidget(videos[6], 1, 1);

    mainLayout->addLayout(smallLayout, 1, 1);
    
    
    setLayout(mainLayout);
}

void KDESS::EightScreensLayout(){
    QGridLayout *mainLayout = new QGridLayout;

    /*
     * 3x3
     */
  
    mainLayout->setSpacing(0);
    
    mainLayout->addWidget(videos[0], 0, 0, 3, 3);  
    mainLayout->addWidget(videos[1], 0, 3);
    mainLayout->addWidget(videos[2], 1, 3);
    mainLayout->addWidget(videos[3], 2, 3);
    mainLayout->addWidget(videos[4], 3, 3);
    mainLayout->addWidget(videos[5], 3, 0);
    mainLayout->addWidget(videos[6], 3, 1);
    mainLayout->addWidget(videos[7], 3, 2);

    setLayout(mainLayout);

    
}

void KDESS::NineScreensLayout(){
    QGridLayout *mainLayout = new QGridLayout;

    /*
     * 3x3
     */
    mainLayout->setSpacing(0);

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
                mainLayout->addWidget(videos[(i*3)+j], i, j);
    }

    setLayout(mainLayout);
}

void KDESS::ThirteenScreensLayout(){
    QGridLayout *mainLayout = new QGridLayout;

    /*
     * 4x4
     */
    mainLayout->setSpacing(0);
  
    mainLayout->addWidget(videos[0], 0, 0);  
    mainLayout->addWidget(videos[1], 0, 1);
    mainLayout->addWidget(videos[2], 0, 2);
    mainLayout->addWidget(videos[3], 0, 3);
    
    mainLayout->addWidget(videos[4], 1, 0);
    mainLayout->addWidget(videos[5], 2, 0);
    mainLayout->addWidget(videos[6], 3, 0);
    
    mainLayout->addWidget(videos[7], 3, 1);
    mainLayout->addWidget(videos[8], 3, 2);
    mainLayout->addWidget(videos[9], 3, 3);
    
    mainLayout->addWidget(videos[10], 1, 3);
    mainLayout->addWidget(videos[11], 2, 3);
    
    mainLayout->addWidget(videos[12], 1, 1, 2, 2);

    setLayout(mainLayout);
    
}

void KDESS::SixteenScreensLayout(){
    QGridLayout *mainLayout = new QGridLayout;

    /*
     * 4x4
     */
    mainLayout->setSpacing(0);

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++)
                mainLayout->addWidget(videos[(i*4)+j], i, j);
    }

    setLayout(mainLayout);

    
}

void KDESS::TwentyScreensLayout(){

    QGridLayout *mainLayout = new QGridLayout;

    QGridLayout *smallLayoutLeft = new QGridLayout;
    QGridLayout *smallLayoutRight = new QGridLayout;

    /*
     * mainLayout 6x6
     */

    mainLayout->setSpacing(0);
    mainLayout->addWidget(videos[0], 0, 0);
    mainLayout->addWidget(videos[1], 0, 1);
    mainLayout->addLayout(smallLayoutLeft, 1, 0);
    mainLayout->addLayout(smallLayoutRight, 1, 1);

    smallLayoutLeft->setSpacing(0);
    smallLayoutRight->setSpacing(0);

    /*
     * smallLayout 3x3
     */

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
            {
                smallLayoutLeft->addWidget(videos[2+(i*3)+j], i, j);
                smallLayoutRight->addWidget(videos[11+(i*3)+j], i, j);
            }
    }
    
    setLayout(mainLayout);
    
}


void KDESS::TwentyFiveScreensLayout(){
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSpacing(0);

    /*
     * 5x5
     */
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++)
                mainLayout->addWidget(videos[(i*5)+j], i, j);
    }

    setLayout(mainLayout);
}

void KDESS::ThirtySixScreensLayout(){
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSpacing(0);

    /*
     * 6x6
     */
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++)
                mainLayout->addWidget(videos[(i*6)+j], i, j);
    }

    setLayout(mainLayout);
}

void KDESS::FourtyNineScreensLayout(){
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSpacing(0);

    /*
     * 7x7
     */
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++)
                mainLayout->addWidget(videos[(i*7)+j], i, j);
    }

    setLayout(mainLayout);
    
}

void KDESS::SixtyFourScreensLayout(){
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSpacing(0);

    /*
     * 8x8
     */
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++)
                mainLayout->addWidget(videos[(i*8)+j], i, j);
    }

    setLayout(mainLayout);
    
}
