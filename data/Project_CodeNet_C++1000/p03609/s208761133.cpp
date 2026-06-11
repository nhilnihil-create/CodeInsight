// In the name of ALlah //
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 * 5 + 10 , inf = 1e9;
int n , m;
void solve(){
    cout << max(0 , n - m);
}
void in (){
    cin >> n >> m;
    solve();
    
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    in();
}
