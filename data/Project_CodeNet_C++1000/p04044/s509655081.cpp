#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int n,l;
    cin >> n >> l;
    string a[n];
    rep(i,n){
       cin >> a[i];
    }
    sort(a,a+n);
   string t;
   rep(i,n) t += a[i];
   cout << t << endl;
}
