#include <bits//stdc++.h>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];
    int ans = 0;
    rep(i,n){
        if(i==a[a[i]-1]-1) ans++;
    } 
    cout << ans/2 << endl;
    return 0;
}