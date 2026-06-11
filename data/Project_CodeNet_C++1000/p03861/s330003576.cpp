#include<bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 2e5 + 77;
int A[N];
// string s;

void sol(){
    int a , b , x ; cin >> a >> b >> x;
    int ans = b/x - a/x + (a%x==0);
    cout << ans << endl;
}  

int32_t main(){
    fast;
    int t = 1; 
    // cin >> t; 
    while(t--) sol();    
    return 0;
}