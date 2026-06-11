#include<iostream>
#include<cmath>

using namespace std;

char getMoveChar1(int path){
    switch(path){
        case 1:
            return 'U';
        case 2:
            return 'D';
        case 3:
            return 'U';
        case 4:
            return 'D';
    }
}

char getMoveChar2(int path){
    switch(path){
        case 1:
            return 'R';
        case 2:
            return 'L';
        case 3:
            return 'R';
        case 4:
            return 'L';
    }
}


int main(){
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int dy = ty - sy;
    int dx = tx - sx;
    for(int path=1; path<=4; path++){
            int len1 = dy;
            int len2 = dx;
            if(path == 3){
                len1++;
                len2++;
                cout << 'L';
            }else if(path == 4){
                len1++;
                len2++;
                cout << 'R';
            }
            for(int i=0; i<len1; i++){
                cout << getMoveChar1(path);
            }
            for(int i=0; i<len2; i++){
                cout << getMoveChar2(path);
            }
            if(path == 3){
                cout << 'D';
            }else if(path == 4){
                cout << 'U';
            }
    }
}

