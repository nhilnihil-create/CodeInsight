#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N,A,B,C,D;
    cin >> N >> A >>B >>C >> D;
    --N;
    for(int i=0;i<N;i++){
        ll diff = abs(B-A);
        if((diff>= (C *(N-i) -i*D)) &&(diff<= (D*(N-i)-i*C))){
            // cerr <<"i=" <<i <<"lower = " <<C *(N-i) -i*D <<" upper=" << D*(N-i)-i*C << endl;
            cout <<"YES" << endl;
            return 0;
        } 
    }
    cout <<"NO" << endl;

    return 0;
}