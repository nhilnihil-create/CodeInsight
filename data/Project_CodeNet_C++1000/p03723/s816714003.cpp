#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll A,B,C,_A,_B,_C;
    cin >> A >> B >> C;
    int ans = 0;
    while(true){
        if(A == B && B == C && C == A && A%2 == 0){
            ans = -1;
            break;
        }
        if(A%2 == 1 || B%2 == 1 || C%2 == 1){
            break;
        }
        _A = A;_B = B;_C = C;
        A = (_B + _C)/2;
        B = (_A + _C)/2;
        C = (_A + _B)/2;
        ans++;
    }
    cout << ans << endl;
}