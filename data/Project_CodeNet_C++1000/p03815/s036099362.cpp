// X: Yet Another Die Game
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll x;
    cin >> x;
    ll ans=x/11*2;
    if(x%11!=0 && x%11<=6){ans++;}
    else if(x%11>=7){ans+=2;}
    cout << ans << endl;
    return 0;
}