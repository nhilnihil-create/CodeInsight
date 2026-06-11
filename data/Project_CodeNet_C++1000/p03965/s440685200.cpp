#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,l,r) for (ll i = (ll)l; i < (ll)(r); i++)

int main(){
    string s ; cin >> s;
    ll n = s.size();
    char tar = 'g';
    ll ret=0;
    rep(i,0,n){
        if(s[i]=='g' && tar=='p') ret++;
        else if(s[i]=='p' && tar=='g') ret--;

        if(tar == 'g') tar = 'p';
        else if(tar == 'p') tar = 'g';
    }
    cout << ret << endl;
}