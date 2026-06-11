#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll a, b;
    string ans;
    cin >> a >> b;
    if(a*b <= 0) ans = "Zero";
    else{
        if(a > 0) ans = "Positive";
        else if((b-a+1)%2 == 0) ans = "Positive";
        else ans = "Negative";
    }
    cout << ans << endl;
    return 0;
}