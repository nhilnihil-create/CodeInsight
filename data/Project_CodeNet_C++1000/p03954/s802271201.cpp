#include <bits/stdc++.h>
using namespace std;

int N, A[200000];

bool check(int k){
    bitset<200000> large;
    for(int i=1; i<=2*N-1; i++) large[i] = (A[i] >= k);

    int lsign = -1, ldist, rsign = -1, rdist;
    for(int i=N; i+1<=2*N-1; i++){
        if(large[i] == large[i+1]){
            rdist = i - N;
            rsign = large[i];
            break;
        }
    }
    for(int i=N; i-1>=1; i--){
        if(large[i] == large[i-1]){
            ldist = N - i;
            lsign = large[i];
            break;
        }
    }
    
    if(lsign == -1 && rsign == -1){
        return (large[N] + N + 1) % 2;
    }else if(lsign == -1 || rsign == -1){
        return max(lsign, rsign);
    }else{
        return (ldist < rdist ? lsign : rsign);
    }
}

int main(){
    cin >> N;
    for(int i=1; i<=2*N-1; i++) cin >> A[i];

    int ok = 1, ng = 2*N;
    while(ng-ok>1){
        int mid = (ok+ng)/2;
        (check(mid) ? ok : ng) = mid;
    }
    cout << ok << endl;
    return 0;
}