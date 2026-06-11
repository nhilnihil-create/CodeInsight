#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a, b;    cin >> a >> b;
    string ans = "Positive";
    if(a<=0 && 0<=b) ans = "Zero";
    else if(b<0 && (b-a+1)%2==1) ans = "Negative"; 
    cout << ans << endl;
}