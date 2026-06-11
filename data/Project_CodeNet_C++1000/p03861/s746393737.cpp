#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

int main(){
    ll a, b, x;
    cin >> a >> b >> x;
    ll fb=0, fa=0;
    if(b>=0)
        fb = b/x+1;
    if(a-1>=0)
        fa = (a-1)/x+1;
    
    cout << fb-fa;
}
