#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n,odd=0;
    cin >> n;
    int a[n];
    rep(i,n){
        cin >> a[i];
        if(a[i]%2) odd++;
    } 
    if(odd%2==0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
