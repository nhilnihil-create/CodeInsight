#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;


ull gcd(ull x, ull y){ return (x%y)? gcd(y, x%y) : y;}
ull lcm(ull x, ull y){ return x / gcd(x, y) * y;}

int main(){
    int n; cin >>n;
    vector<ull> t(100);
    ull ans = 0;
    for(int i=0; i<n; i++){
        cin >> t[i];
        if(i==0) ans = t[i];
        else{
            ans = lcm(ans, t[i]);
        }
    }
    cout << ans << endl;
    return 0;
}