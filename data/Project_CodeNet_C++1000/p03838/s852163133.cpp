#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll A,B;
    cin >> A >>B;
    ll ans =0;
    if(A*B<0){
        ans++;
        A *= (-1);
        
    }else if(A*B==0){
        if(A>B){
            ans++;
        }
    }else{
        if( A >B ){
            ans+=2;
        }
    }
    ans += abs(B-A);
    cout << ans << endl;


    return 0;
}