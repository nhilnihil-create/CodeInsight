#include <bits/stdc++.h>

using namespace std;

int main(){
    int H,W,N;
    int now=0;
    bool right=true;
    cin >> H >> W;
    cin >> N;
    vector<int> a(N);
    int A[H][W];
    for(int i=0;i<N;i++){
        cin >> a[i];
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(right){
                A[i][j] = now+1;
                a[now]--;
                if(a[now]==0){
                    now++;
                }
            }else{
                A[i][W-1-j] = now+1;
                a[now]--;
                if(a[now]==0){
                    now++;
                }
            }
        }
        if(right){
            right = false;
        }else{
            right = true;
        }
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout << A[i][j];
            if(j==W-1){
                cout << endl;
            }else{
                cout << " ";
            }
        }
    }
}