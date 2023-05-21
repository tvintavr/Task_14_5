#include <iostream>
#include <vector>
#include <cassert>


int main() {
    bool pops[12][12];

    //true - целый

    for (int i=0;i<12;i++) {
        for (int j=0;j<12;j++) {
            pops[i][j]=true;
        }
    }

    for (int i=-1;i<12;i++) {
        for (int j=-1;j<12;j++) {
            if (i==-1 & j==-1) {
                std::cout<<" "<<"\t";
            }
            else if (i==-1) {
                std::cout<<j<<"\t";
            } else if (j==-1) {
                std::cout<<i<<"\t";
            }
            else if (pops[i][j]) {
                std::cout<<"O"<<"\t";
            } else {
                std::cout<<"X"<<"\t";
            }
        }
        std::cout<<std::endl;
    }

    int count=12*12;

    while (count>0) {
        std::cout<<"Input coordinates of point #1(0..11,0..11): ";
        int xOne;
        int yOne;
        std::cin>>xOne>>yOne;
        assert(xOne>=0);
        assert(xOne<=12);
        assert(yOne>=0);
        assert(yOne<=12);
        assert(!std::cin.fail());

        std::cout<<"Input coordinates of point #2(0..11,0..11): ";
        int xTwo;
        int yTwo;
        std::cin>>xTwo>>yTwo;
        assert(xTwo>=0);
        assert(xTwo<=11);
        assert(yTwo>=0);
        assert(yTwo<=11);
        assert(!std::cin.fail());

        //xOne s.b. smaller than xTwo
        //yOne s.b. smaller than yTwo

        if (yOne>yTwo) {
            yTwo=yTwo+yOne;
            yOne=yTwo-yOne;
            yTwo=yTwo-yOne;
        }

        if (xOne>xTwo) {
            xTwo=xTwo+xOne;
            xOne=xTwo-xOne;
            xTwo=xTwo-xOne;
        }

    std::cout<<std::endl;

        for (int i=yOne;i<=yTwo;i++) {
            for (int j=xOne;j<=xTwo;j++) {
                if (pops[i][j]) {
                    pops[i][j]=false;
                    std::cout<<"Pop!";
                    std::cout<<std::endl;
                    count--;
                };
            }
        }

        for (int i=-1;i<12;i++) {
            for (int j=-1;j<12;j++) {
                if (i==-1 & j==-1) {
                    std::cout<<" "<<"\t";
                }
                else if (i==-1) {
                    std::cout<<j<<"\t";
                } else if (j==-1) {
                    std::cout<<i<<"\t";
                }
                else if (pops[i][j]) {
                    std::cout<<"O"<<"\t";
                } else {
                    std::cout<<"X"<<"\t";
                }
            }
            std::cout<<std::endl;
        }




    }








}