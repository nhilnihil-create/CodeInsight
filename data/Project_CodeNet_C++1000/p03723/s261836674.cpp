#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll A,B,C;
    cin >> A >> B >> C;
    if (A == B &&  B == C){
        if (A % 2 == 1){
            cout << 0 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    else{
        ll count = 0;
        while(true){
            if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1){
                break;
            }
            else{
                ll P = (B + C) / 2;
                ll Q = (C + A) / 2;
                ll R = (A + B) / 2;
                A = P;
                B = Q;
                C = R;
                count++;
            }
        }
        cout << count << endl;
    }
}