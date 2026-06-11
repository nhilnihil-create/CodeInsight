#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){    
    ll A,B,C;
    cin >> A >> B >> C;
    if(A == B && B == C){
        if(A%2 == 0){
            cout << -1 << endl;
        }else{
            cout << 0 << endl;
        }
    }else{
        int ans = 0;
        ll A1,B1,C1;
        while(A%2==0 && B%2 == 0 && C%2 == 0){
            A1 = (A+B)/2;
            B1 = (A+C)/2;
            C1 = (B+C)/2;
            ans += 1;
            A = A1;
            B = B1;
            C = C1;
        }
        cout << ans << endl;
    }
}