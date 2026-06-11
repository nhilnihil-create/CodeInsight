#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    string S; cin >> S;
    int sz = S.size();
    ll all_ptn = pow(2,sz-1);
    ll ans =0;
    reverse(S.begin(),S.end());

    for(int ptn=0; ptn<all_ptn; ptn++){
        ll d=1;
        for(int i=0; i<sz-1; i++){
            ans += (S.at(i) - '0')*d;
            if((ptn >> i)& 1) d=1;
            else d *= 10;
        }
        ans += (S.at(sz-1) -'0') *d;
    }
        
    cout << ans << endl;
}