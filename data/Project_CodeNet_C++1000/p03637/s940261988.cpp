#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int d2=0, d4=0;
    rep(i, n){
        int x;
        cin >> x;
        if(x%4 == 2){
            d2 ++;
        }
        else if(x%4==0){
            d4 ++;
        }
    }
    n -= (d2-d2%2) + d4;
    d2 = d2%2;
    if(d4 >= n-1){
        cout << "Yes";
    }
    else cout << "No";
    return 0;
}
