#include <iostream>

using namespace std;

int main()
{
    int H,W,x1,y1;
    cin >> H >> W;
    string array[H][W];
    for(int x=0;x<H;x++){
        for(int y=0;y<W;y++){
            cin >> array[x][y];
            cin.get();
        }
    }
    for(int x=0;x<H;x++){
        for(int y=0;y<W;y++){
            if(array[x][y]=="snuke"){
                x1 = x+1;
                y1 = y+1;
            }
        }
    }
    if(y1==1){
        cout << "A" << x1 << endl;
    }else if(y1==2){
        cout << "B" << x1 << endl;
    }else if(y1==3){
        cout << "C" << x1 << endl;
    }else if(y1==4){
        cout << "D" << x1 << endl;
    }else if(y1==5){
        cout << "E" << x1 << endl;
    }else if(y1==6){
        cout << "F" << x1 << endl;
    }else if(y1==7){
        cout << "G" << x1 << endl;
    }else if(y1==8){
        cout << "H" << x1 << endl;
    }else if(y1==9){
        cout << "I" << x1 << endl;
    }else if(y1==10){
        cout << "J" << x1 << endl;
    }else if(y1==11){
        cout << "K" << x1 << endl;
    }else if(y1==12){
        cout << "L" << x1 << endl;
    }else if(y1==13){
        cout << "M" << x1 << endl;
    }else if(y1==14){
        cout << "N" << x1 << endl;
    }else if(y1==15){
        cout << "O" << x1 << endl;
    }else if(y1==16){
        cout << "P" << x1 << endl;
    }else if(y1==17){
        cout << "Q" << x1 << endl;
    }else if(y1==18){
        cout << "R" << x1 << endl;
    }else if(y1==19){
        cout << "S" << x1 << endl;
    }else if(y1==20){
        cout << "T" << x1 << endl;
    }else if(y1==21){
        cout << "U" << x1 << endl;
    }else if(y1==22){
        cout << "V" << x1 << endl;
    }else if(y1==23){
        cout << "W" << x1 << endl;
    }else if(y1==24){
        cout << "X" << x1 << endl;
    }else if(y1==25){
        cout << "Y" << x1 << endl;
    }else if(y1==26){
        cout << "Z" << x1 << endl;
    }
}