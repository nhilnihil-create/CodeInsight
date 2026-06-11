#include <bits/stdc++.h>
using namespace std;

long long GCD(long long x,long long y){
    if(y == 0)return x;
    return GCD(y,x%y);
}

int main(){
    int N;
    long long K;
    cin >> N >> K;
    long long ma = 0, g = 0;
    for(int i = 0; i < N;i++){
        long long a;cin >> a;
        ma = max(ma,a);
        g = GCD(g,a);
    }
    
    if(K <= ma && K%g == 0)cout << "POSSIBLE" <<endl;
    else cout << "IMPOSSIBLE" << endl;
    
}