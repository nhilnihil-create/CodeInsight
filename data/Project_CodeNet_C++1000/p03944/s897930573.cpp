#include <bits/stdc++.h>
using namespace std;

int main(){
    int W,H,N;
    cin>>W>>H>>N;
    int count = 0;//白の面積
    vector<vector<string>>data(W,vector<string>(H));
    for(int w = 0;w < W;w++){
        for(int h = 0;h < H;h++){
            data.at(w).at(h) = "白";
        }
    }
    for(int i = 0;i < N;i++){//長方形の色をぬりつぶす処理
        vector<int> a(3);
        for(int i = 0;i < 3;i++){
            cin>>a.at(i);
        }
        if(a.at(2) == 1){//パターン１の処理
            for(int w = 0;w < a.at(0);w++){
                for(int h = 0;h < H;h++){
                    data.at(w).at(h) = "黒";
                }
            }
        }
        if(a.at(2) == 2){//パターン２の処理
            for(int w = 0;w < W;w++){
                for(int h = 0;h < H;h++){
                    if(w >= a.at(0)){
                        data.at(w).at(h) = "黒";
                    }
                }
            }
        }
        if(a.at(2) == 3){//パターン３の処理
            for(int w = 0;w < W;w++){
                for(int h = 0;h < a.at(1);h++){
                    data.at(w).at(h) = "黒";
                }
            }
        }
        if(a.at(2) == 4){//パターン４の処理
            for(int w = 0;w < W;w++){
                for(int h = 0;h < H;h++){
                    if(h >= a.at(1)){
                        data.at(w).at(h) = "黒";
                    }
                }
            }
        }
    }
    for(int w = 0;w < W;w++){//白の面積を求める処理
        for(int h = 0;h < H;h++){
            if(data.at(w).at(h) == "白"){
                count++;
            }
        }
    }
    cout<<count<<endl;
}