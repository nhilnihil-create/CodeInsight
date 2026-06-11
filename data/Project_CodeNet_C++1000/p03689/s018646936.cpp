#include <iostream>

using namespace std;

int main(){
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    if(H%h == 0 && W%w == 0){
        cout << "No" << endl;
    }else if(H%h != 0){
        cout << "Yes" << endl;
        int tmp = 1;
        while(tmp <= 500){
            tmp = tmp*h+1;
        }
        int large = (h-1)*tmp+1;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if((i+1)%h != 0) cout << tmp;
                else cout << -large;
                if(j != W-1) cout << ' ';
            }
            cout << endl;
        }
    }else{
        cout << "Yes" << endl;
        int tmp = 1;
        while(tmp <= 500){
            tmp = tmp*w+1;
        }
        int large = (w-1)*tmp+1;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if((j+1)%w != 0) cout << tmp;
                else cout << -large;
                if(j != W-1) cout << ' ';
            }
            cout << endl;
        }
    }
}