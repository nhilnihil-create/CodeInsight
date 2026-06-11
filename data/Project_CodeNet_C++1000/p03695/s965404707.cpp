#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    ll red = 0;
    set<ll> st;
    rep(i, 0, n){
        ll a;
        cin >> a;
        if(a >= 3200) red++;
        else st.insert(a / 400);
    }
    cout << max(1LL, (ll)st.size()) << " ";
    cout << st.size() + red << endl;
    return 0;
}