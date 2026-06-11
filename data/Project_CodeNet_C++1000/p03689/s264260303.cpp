#include<iostream>
using namespace std;

int H, W, h, w;
int main(){
    cin >> H >> W >> h >> w;
    if(H % h == 0 && W % w == 0){
        cout << "No" << endl;
        return 0;
    }else if(H % h != 0){
        cout << "Yes" << endl;
        // i % h == 0 => s[i] = - (i/h)
        // otherwise => s[H-h+1, ..., H] = 1; s[i] = (H - i) / h + 1
        int a[500] = {}, s[501] = {};
        for(int i = 0; i <= H; i++){
            if(i % h){
                s[i] = (H - i) / h + 1;
            }else{
                s[i] = - (i/h);
            }
        }
        for(int i = 0; i < H; i++){
            a[i] = s[i+1] - s[i];
        }
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(j){
                    cout << " ";
                }
                cout << a[i];
            }
            cout << endl;
        }
    }else{
        cout << "Yes" << endl;
        int s[501] = {}, a[500] = {};
        for(int j = 0; j <= W; j++){
            if(j % w){
                s[j] = (W - j) / w + 1;
            }else{
                s[j] = - (j / w);
            }
        }
        for(int j = 0; j < W; j++){
            a[j] = s[j+1] - s[j];
        }
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(j){
                    cout << " ";
                }
                cout << a[j];
            }
            cout << endl;
        }
    }
    
}
