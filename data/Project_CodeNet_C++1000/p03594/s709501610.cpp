#include <iostream>

using namespace std;

string str[500];

int h,w,d;
void shape(int y,int x,char c){
    for(int i = 0;i < d;i++){
        int sx = x+i;
        int hb = min(i,d-i-1);
        for(int j = -hb;j <= hb;j++){
            int sy = y+j;
            if(0 <= sx && sx < w && 0 <= sy && sy < h){
                str[sy][sx] = c;
            }
        }
    }
}

int main(){
    cin >> h >> w >> d;
    for(int i = 0;i < h;i++){
        str[i] = string(w,' ');
    }
    if(d%2){
        for(int i = 0;i < h;i++){
            for(int j = 0;j < w;j++){
                if(i%2 == 0 && j%2 == 0){
                    str[i][j] = 'R';
                }
                if(i%2 == 0 && j%2 == 1){
                    str[i][j] = 'Y';
                }
                if(i%2 == 1 && j%2 == 0){
                    str[i][j] = 'G';
                }
                if(i%2 == 1 && j%2 == 1){
                    str[i][j] = 'B';
                }
            }
        }
    }
    else{
        for(int i = 0;;i++){
            int sy = -d+i*d;
            if(sy > h+d) break;
            for(int j = 0;;j++){
                int sx = -d*2+j*d*2;
                if(i%2) sx -= d;
                if(sx > w) break;
                shape(sy,sx,'R');
                shape(sy,sx+d,'Y');
                shape(sy-d/2,sx+d/2,'G');
                shape(sy+d/2,sx+d/2,'B');
            }
        }
    }
    for(int i = 0;i < h;i++){
        cout << str[i] << endl;
    }
}