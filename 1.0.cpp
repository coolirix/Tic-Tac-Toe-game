#include<simplecpp>
void cross(int x1,int x2,int y1,int y2,int& a,int& s){
    Line l(x1+20,y1+20,x2-20,y2-20),q(x1+20,y2-20,x2-20,y1+20);
    l.imprint();q.imprint();a=l.getX();s=l.getY();
    return;
}
void zero(int x1,int x2,int y1,int y2,int& g,int& h){
    int x=(x1+x2)/2;int y=(y1+y2)/2;
    Circle c(x,y,60);
    c.imprint();g=x;h=y;
    return;
}
void block(int x,int y,int& x1,int& x2,int& y1,int& y2){
    if(x>=260 && x<=420 && y>=120 && y<=280){x1=260;x2=420;y1=120;y2=280;}
    else if(x>=420 && x<=580 && y>=120 && y<=280){x1=420;x2=580;y1=120;y2=280;}
    else if(x>=580 && x<=740 && y>=120 && y<=280){x1=580;x2=740;y1=120;y2=280;}
    else if(x>=260 && x<=420 && y>=280 && y<=440){x1=260;x2=420;y1=280;y2=440;}
    else if(x>=420 && x<=580 && y>=280 && y<=440){x1=420;x2=580;y1=280;y2=440;}
    else if(x>=580 && x<=740 && y>=280 && y<=440){x1=580;x2=740;y1=280;y2=440;}
    else if(x>=260 && x<=420 && y>=440 && y<=600){x1=260;x2=420;y1=440;y2=600;}
    else if(x>=420 && x<=580 && y>=440 && y<=600){x1=420;x2=580;y1=440;y2=600;}
    else if(x>=580 && x<=740 && y>=440 && y<=600){x1=580;x2=740;y1=440;y2=600;}
    return;
}
void pcross(int x,int y,int& x1,int& x2,int& y1,int& y2,int& w,int& a,int& s){
    if(x>=260 && x<=740 && y>=120 && y<=600){
        block(x,y,x1,x2,y1,y2);cross(x1,x2,y1,y2,a,s);
    }
    else{
        while(x<=260 || x>=740 || y<=120 || y>=600){
            cout<<"mark properly"<<endl;w=getClick();x=w/65536;y=w%65536;
        }
        block(x,y,x1,x2,y1,y2);cross(x1,x2,y1,y2,a,s);
    }
    return;
}
void pzero(int x,int y,int& x1,int& x2,int& y1,int& y2,int& w,int& g,int& h){
    if(x>=260 && x<=740 && y>=120 && y<=600){
        block(x,y,x1,x2,y1,y2);zero(x1,x2,y1,y2,g,h);
    }
    else{
        while(x<=260 || x>=740 || y<=120 || y>=600){
            cout<<"mark properly"<<endl;w=getClick();x=w/65536;y=w%65536;
        }
        block(x,y,x1,x2,y1,y2);zero(x1,x2,y1,y2,g,h);
    }
    return;
}
void p1(int x1,int y1,int x2,int y2,int x3,int y3,int& v){
    Line l1(x1,y1,x2,y2),l2(x2,y2,x3,y3);l1.scale(1.9);l2.scale(1.9);l1.imprint();l2.imprint();
    Rectangle r1(100,100,110,30),r2(100,150,110,30);Text t1(100,100,"Player 1 Wins"),t2(100,150,"GAME OVER");
    r1.imprint();r2.imprint();t1.imprint();t2.imprint();v=1;
}
void p2(int x1,int y1,int x2,int y2,int x3,int y3,int& v){
    Line l1(x1,y1,x2,y2),l2(x2,y2,x3,y3);l1.scale(1.9);l2.scale(1.9);l1.imprint();l2.imprint();
    Rectangle r1(100,100,110,30),r2(100,150,110,30);Text t1(100,100,"Player 2 Wins"),t2(100,150,"GAME OVER");
    r1.imprint();r2.imprint();t1.imprint();t2.imprint();v=1;
}
void check1(int a1,int a2,int a3,int a4,int s1,int s2,int s3,int s4,int g1,int g2,int g3,int g4,int g5,int h1,int h2,int h3,int h4,int h5,int& v){
    if(((s2-s1)*(a3-a2))==((s3-s2)*(a2-a1))){p2(a1,s1,a2,s2,a3,s3,v);}
    else if(((s2-s1)*(a4-a2))==((s4-s2)*(a2-a1))){p2(a1,s1,a2,s2,a4,s4,v);}
    else if(((s3-s2)*(a4-a3))==((s4-s3)*(a3-a2))){p2(a2,s2,a3,s3,a4,s4,v);}
    else if(((s3-s1)*(a4-a3))==((s4-s3)*(a3-a1))){p2(a1,s1,a3,s3,a4,s4,v);}
    else if(((h2-h1)*(g3-g2))==((h3-h2)*(g2-g1))){p1(g1,h1,g2,h2,g3,h3,v);}
    else if(((h2-h1)*(g4-g2))==((h4-h2)*(g2-g1))){p1(g1,h1,g2,h2,g4,h4,v);}
    else if(((h2-h1)*(g5-g2))==((h5-h2)*(g2-g1))){p1(g1,h1,g2,h2,g5,h5,v);}
    else if(((h4-h1)*(g5-g4))==((h5-h4)*(g4-g1))){p1(g1,h1,g4,h4,g5,h5,v);}
    else if(((h3-h2)*(g4-g3))==((h4-h3)*(g3-g2))){p1(g2,h2,g3,h3,g4,h4,v);}
    else if(((h3-h2)*(g5-g3))==((h5-h3)*(g3-g2))){p1(g2,h2,g3,h3,g5,h5,v);}
    else if(((h4-h2)*(g5-g4))==((h5-h4)*(g4-g2))){p1(g2,h2,g4,h4,g5,h5,v);}
    else if(((h4-h3)*(g5-g4))==((h5-h4)*(g4-g3))){p1(g3,h3,g4,h4,g5,h5,v);}
    else if(((h4-h3)*(g4-g1))==((h4-h1)*(g4-g3))){p1(g1,h1,g3,h3,g4,h4,v);}
    else if(((h3-h1)*(g5-g3))==((h5-h3)*(g3-g1))){p1(g1,h1,g3,h3,g5,h5,v);}
    else{v=0;}
return;
}
void check2(int a1,int a2,int a3,int a4,int a5,int s1,int s2,int s3,int s4,int s5,int g1,int g2,int g3,int g4,int h1,int h2,int h3,int h4,int& v){
    if(((h2-h1)*(g3-g2))==((h3-h2)*(g2-g1))){p2(g1,h1,g2,h2,g3,h3,v);}
    else if(((h2-h1)*(g4-g2))==((h4-h2)*(g2-g1))){p2(g1,h1,g2,h2,g4,h4,v);}
    else if(((h3-h2)*(g4-g3))==((h4-h3)*(g3-g2))){p2(g2,h2,g3,h3,g4,h4,v);}
    else if(((h3-h1)*(g4-g3))==((h4-h3)*(g3-g1))){p2(g1,h1,g3,h3,g4,h4,v);}
    else if(((s2-s1)*(a3-a2))==((s3-s2)*(a2-a1))){p1(a1,s1,a2,s2,a3,s3,v);}
    else if(((s2-s1)*(a4-a2))==((s4-s2)*(a2-a1))){p1(a1,s1,a2,s2,a4,s4,v);}
    else if(((s2-s1)*(a5-a2))==((s5-s2)*(a2-a1))){p1(a1,s1,a2,s2,a5,s5,v);}
    else if(((s4-s1)*(a5-a4))==((s5-s4)*(a4-a1))){p1(a1,s1,a4,s4,a5,s5,v);}
    else if(((s3-s2)*(a4-a3))==((s4-s3)*(a3-a2))){p1(a2,s2,a3,s3,a4,s4,v);}
    else if(((s3-s2)*(a5-a3))==((s5-s3)*(a3-a2))){p1(a2,s2,a3,s3,a5,s5,v);}
    else if(((s4-s2)*(a5-a4))==((s5-s4)*(a4-a2))){p1(a2,s2,a4,s4,a5,s5,v);}
    else if(((s4-s3)*(a5-a4))==((s5-s4)*(a4-a3))){p1(a3,s3,a4,s4,a5,s5,v);}
    else if(((s4-s3)*(a4-a1))==((s4-s1)*(a4-a3))){p1(a1,s1,a3,s3,a4,s4,v);}
    else if(((s3-s1)*(a5-a3))==((s5-s3)*(a3-a1))){p1(a1,s1,a3,s3,a5,s5,v);}
    else{v=0;}
return;
}
main_program{
int x1,x2,y1,y2,v;x1=0;x2=0;y1=0;y2=0;v=0;
initCanvas("Tic-Tac-Toe",1000,700);
Line l1(420,120,420,600),l2(580,120,580,600),l3(260,280,740,280),l4(260,440,740,440),l5(870,140,930,200),l6(930,140,870,200);
Text t1(500,50,"Tic-Tac-Toe"),t2(800,70,"Player 1");
Rectangle r1(500,50,100,40),r2(800,70,60,30),r3(900,80,70,70),r4(900,170,70,70);
Circle c9(900,80,30);
l1.imprint();l2.imprint();l3.imprint();l4.imprint();l5.imprint();l6.imprint();
t1.imprint();t2.imprint();
r1.imprint();r2.imprint();r3.imprint();r4.imprint();
c9.imprint();
int m=getClick();int p=m/65536;int q=m%65536;
if(p>=865 && p<=935 && q>=45 && q<=115){
    int a1,a2,a3,a4,s1,s2,s3,s4,g1,g2,g3,g4,g5,h1,h2,h3,h4,h5;
    a1=421;a2=425;a3=580;a4=583;s1=440;s2=441;s3=443;s4=446;g1=421;g2=425;g3=580;g4=583;g5=587;h1=440;h2=441;h3=443;h4=446;h5=450;
    int w=getClick();int x=w/65536;int y=w%65536;
    pzero(x,y,x1,x2,y1,y2,w,g1,h1);
    w=getClick();x=w/65536;y=w%65536;
    pcross(x,y,x1,x2,y1,y2,w,a1,s1);
    w=getClick();x=w/65536;y=w%65536;
    pzero(x,y,x1,x2,y1,y2,w,g2,h2);
    w=getClick();x=w/65536;y=w%65536;
    pcross(x,y,x1,x2,y1,y2,w,a2,s2);
    w=getClick();x=w/65536;y=w%65536;
    pzero(x,y,x1,x2,y1,y2,w,g3,h3);
    check1(a1,a2,a3,a4,s1,s2,s3,s4,g1,g2,g3,g4,g5,h1,h2,h3,h4,h5,v);
    if(v==1){getClick();}
    else{
        w=getClick();x=w/65536;y=w%65536;
        pcross(x,y,x1,x2,y1,y2,w,a3,s3);
        check1(a1,a2,a3,a4,s1,s2,s3,s4,g1,g2,g3,g4,g5,h1,h2,h3,h4,h5,v);
        if(v==1){getClick();}
        else{
            w=getClick();x=w/65536;y=w%65536;
            pzero(x,y,x1,x2,y1,y2,w,g4,h4);
            check1(a1,a2,a3,a4,s1,s2,s3,s4,g1,g2,g3,g4,g5,h1,h2,h3,h4,h5,v);
            if(v==1){getClick();}
            else{
                w=getClick();x=w/65536;y=w%65536;
                pcross(x,y,x1,x2,y1,y2,w,a4,s4);
                check1(a1,a2,a3,a4,s1,s2,s3,s4,g1,g2,g3,g4,g5,h1,h2,h3,h4,h5,v);
                if(v==1){getClick();}
                else{
                    w=getClick();x=w/65536;y=w%65536;
                    pzero(x,y,x1,x2,y1,y2,w,g5,h5);
                    check1(a1,a2,a3,a4,s1,s2,s3,s4,g1,g2,g3,g4,g5,h1,h2,h3,h4,h5,v);
                    if(v==1){getClick();}
                    else{
                        Rectangle r11(100,100,110,30),r12(100,150,110,30);
                        Text t11(100,100,"TIE"),t12(100,150,"GAME OVER");
                        r11.imprint();t11.imprint();r12.imprint();t12.imprint();
                    }
                }
            }
        }
    }
}
else if(p>=865 && p<=935 && q>=135 && q<=205){
    int a1,a2,a3,a4,a5,s1,s2,s3,s4,s5,g1,g2,g3,g4,h1,h2,h3,h4;
    a1=421;a2=425;a3=580;a4=583;a5=587;s1=440;s2=441;s3=443;s4=446;s5=450;g1=421;g2=425;g3=580;g4=583;h1=440;h2=441;h3=443;h4=446;
    int w=getClick();int x=w/65536;int y=w%65536;
    pcross(x,y,x1,x2,y1,y2,w,a1,s1);
    w=getClick();x=w/65536;y=w%65536;
    pzero(x,y,x1,x2,y1,y2,w,g1,h1);
    w=getClick();x=w/65536;y=w%65536;
    pcross(x,y,x1,x2,y1,y2,w,a2,s2);
    w=getClick();x=w/65536;y=w%65536;
    pzero(x,y,x1,x2,y1,y2,w,g2,h2);
    w=getClick();x=w/65536;y=w%65536;
    pcross(x,y,x1,x2,y1,y2,w,a3,s3);
    check2(a1,a2,a3,a4,a5,s1,s2,s3,s4,s5,g1,g2,g3,g4,h1,h2,h3,h4,v);
    if(v==1){getClick();}
    else{
        w=getClick();x=w/65536;y=w%65536;
        pzero(x,y,x1,x2,y1,y2,w,g3,h3);
        check2(a1,a2,a3,a4,a5,s1,s2,s3,s4,s5,g1,g2,g3,g4,h1,h2,h3,h4,v);
        if(v==1){getClick();}
        else{
            w=getClick();x=w/65536;y=w%65536;
            pcross(x,y,x1,x2,y1,y2,w,a4,s4);
            check2(a1,a2,a3,a4,a5,s1,s2,s3,s4,s5,g1,g2,g3,g4,h1,h2,h3,h4,v);
            if(v==1){getClick();}
            else{
                w=getClick();x=w/65536;y=w%65536;
                pzero(x,y,x1,x2,y1,y2,w,g4,h4);
                check2(a1,a2,a3,a4,a5,s1,s2,s3,s4,s5,g1,g2,g3,g4,h1,h2,h3,h4,v);
                if(v==1){getClick();}
                else{
                    w=getClick();x=w/65536;y=w%65536;
                    pcross(x,y,x1,x2,y1,y2,w,a5,s5);
                    check2(a1,a2,a3,a4,a5,s1,s2,s3,s4,s5,g1,g2,g3,g4,h1,h2,h3,h4,v);
                    if(v==1){getClick();}
                    else{
                        Rectangle r11(100,100,110,30),r12(100,150,110,30);
                        Text t11(100,100,"TIE"),t12(100,150,"GAME OVER");
                        r11.imprint();t11.imprint();r12.imprint();t12.imprint();
                    }
                }
            }
        }
    }
}
getClick();
}
