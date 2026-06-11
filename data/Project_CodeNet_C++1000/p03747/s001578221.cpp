#include <bits/stdc++.h>
using namespace std;

int main(){
    //入力
    int N, L, T; cin >> N >> L >> T;
    int X[100100], W[100100];
    for(int i=0; i<N; i++){
        cin >> X[i] >> W[i];
    }
    //
    //最終的な位置を計算
    int fin[100100];
    int pos;
    for(int i=0; i<N; i++){
        if(W[i]==1){
            fin[i] = (T+X[i]) % L;
        }
        if(W[i]==2){
            fin[i]= (X[i]-T) %L;
            if(fin[i]<0) fin[i] +=L;
        }
    }
    pos=fin[0];
    sort(fin,fin+N);
    //0が他のものと何回ぶつかるか
    int num=0;
    for(int i=1; i<N; i++){
        if(W[i]==W[0]) continue;
        int dis;
        if(W[0]==1) dis=X[i]-X[0];
        else dis=L-(X[i]-X[0]);
        if(dis > 2*T) continue;
        num += (2*T-dis)/L +1;
    }
    num %=N;
//    cout << num << endl;
    //
    int ans[100100];
    if(W[0]==1){
        int x = upper_bound(fin,fin+N,pos)-fin-1;
        for(int i=0; i<N; i++){
            if(x+i < N){
                ans[(num+i)%N] = fin[x+i];
            }
            else{
                ans[(num+i)%N] = fin[x+i-N];
            }
        }
    }
    else{
        int x =lower_bound(fin,fin+N,pos)-fin;
        for(int i=0; i<N; i++){
            if(x+i<N){
                ans[(N-num+i)%N]=fin[x+i];
            }
            else{
                ans[(N-num+i)%N]=fin[x+i-N];
            }
        }
    }
    for(int i=0; i<N; i++){
        cout << ans[i] << endl;
    }
}