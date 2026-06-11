#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N, L, T;
    int X[100000], W[100000], ans[100000];
    int cnt = 0;
    cin >> N >> L >> T;
    for(int i = 0; i < N; i++){
        cin >> X[i] >> W[i];
        if(W[i] == 1){
            if(T >= (L-X[i])){
                cnt -= (1+(T-(L-X[i]))/L);
            }
            X[i] = (X[i]+T)%L;
        }else{
            if(T > X[i]){
                cnt += (1+(T-X[i]-1)/L);
            }
            X[i] = ((X[i]-T)%L+L)%L;
        }
    }
    cnt = ((cnt%N)+N)%N;
    //cout << cnt << endl;
    sort(X, X+N);
    
    for(int i = 0; i < N; i++){
        ans[i] = X[(i-cnt+N)%N];
    }
    for(int i = 0; i < N; i++){
        cout << ans[i] << '\n';
    }
}