#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

int main(){
    int H,W,N;
    cin >> H >> W >> N;
    vector<int> A(H * W);
    int k=0;
    int a;
    rep(i,N){
        cin >> a;
        rep(j,a){
            A[k] = i+1;
            k++;
        }
    } 
    int C[H][W] = {};
    k=0;
    bool flag = true;
    for(int i=0;i<H;i++){
        for(int j=(flag?0:W-1);0<=j && j<W;){
            C[i][j] = A[k];
            k++;
            if(flag) j++;
            else j--;
        }
        flag ^= 1;
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout << C[i][j] << " ";
        }
            cout << endl;
    }

    return 0;
}