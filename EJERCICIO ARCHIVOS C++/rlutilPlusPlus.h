#ifndef RLUTILPLUSPLUS_H_INCLUDED
#define RLUTILPLUSPLUS_H_INCLUDED

void textAnimation(const char*,int);
void boxAnimation(int,int,int,int,int,int);
void textBoxAnimation(int,int,const char*,int,int);

void textAnimation(const char*text="TEXT",int velocity=0){
    rlutil::hidecursor();
    int t=strlen(text);
    for(int i=0;i<t;i++){
        cout<<text[i];
        if(velocity!=0){
            rlutil::msleep(velocity);
        }
    }
    rlutil::showcursor();
}
void boxAnimation(int x, int y, int tipe=1, int width=20, int height=10, int velocity=10){
    rlutil::hidecursor();
    int i;
        switch(tipe){
    case 1:
        enum Line1{
                    topLeftCorner1   =218, topRightCorner1   =191,
                    horizontalLine1  =196, verticalLine1     =179,
                    bottomLeftCorner1=192, bottomRightCorner1=217,};

        rlutil::locate(x,y);
        std::cout<<(char)topLeftCorner1;
        for(i=1;i<width;i++){std::cout<<(char)horizontalLine1;rlutil::msleep(velocity);}
        std::cout<<(char)topRightCorner1;

        for(i=0;i<height;i++){rlutil::locate(x,++y);std::cout<<(char)verticalLine1;
        rlutil::locate((width+x),y);std::cout<<(char)verticalLine1;rlutil::msleep(velocity);}

        rlutil::locate(x,y);
        std::cout<<(char)bottomLeftCorner1;
        for(i=1;i<width;i++){std::cout<<(char)horizontalLine1;rlutil::msleep(velocity);}
        std::cout<<(char)bottomRightCorner1;
    break;
    case 2:
        enum Line2{
                    topLeftCorner2   =201, topRightCorner2   =187,
                    horizontalLine2  =205, verticalLine2     =186,
                    bottomLeftCorner2=200, bottomRightCorner2=188,};

        rlutil::locate(x,y);
        std::cout<<(char)topLeftCorner2;
        for(i=1;i<width;i++){std::cout<<(char)horizontalLine2;rlutil::msleep(velocity);}
        std::cout<<(char)topRightCorner2;

        for(i=0;i<height;i++){rlutil::locate(x,++y);std::cout<<(char)verticalLine2;
        rlutil::locate((width+x),y);std::cout<<(char)verticalLine2;rlutil::msleep(velocity);}

        rlutil::locate(x,y);
        std::cout<<(char)bottomLeftCorner2;
        for(i=1;i<width;i++){std::cout<<(char)horizontalLine2;rlutil::msleep(velocity);}
        std::cout<<(char)bottomRightCorner2;
    break;
    case 3:
        enum Line3{
                    topHorizontalLine3   =220,
                    bottomHorizontalLine3=223,
                    verticalLine3        =219,};

        rlutil::locate(x,y);
        for(i=0;i<=width;i++){std::cout<<(char)topHorizontalLine3;rlutil::msleep(velocity);}

        for(i=0;i<height;i++){rlutil::locate(x,++y);std::cout<<(char)verticalLine3;
        rlutil::locate((width+x),y);std::cout<<(char)verticalLine3;rlutil::msleep(velocity);}

        rlutil::locate(x,y);
        for(i=0;i<=width;i++){std::cout<<(char)bottomHorizontalLine3;rlutil::msleep(velocity);}
    break;
    }
    rlutil::showcursor();
}
void textBoxAnimation(int x, int y, const char*text="text",int tipe=2,int velocity=1){
    int t=strlen(text);
    rlutil::hidecursor();
    rlutil::setColor(8);
    boxAnimation(x,y,tipe,(t+1),2,velocity);
    rlutil::setColor(15);
    t+=2;
    rlutil::locate(++x,++y);
    textAnimation(text);
    rlutil::showcursor();
    cout<<endl;
}

#endif // RLUTILPLUSPLUS_H_INCLUDED
