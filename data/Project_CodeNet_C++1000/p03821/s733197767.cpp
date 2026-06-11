#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main(){
    int n;
    cin >> n;
    vector <long> a(n), b(n), c(n);
    rep(i,n) cin >> a[i] >> b[i];

    rep(i,n) c[i] = a[i]%b[i];

    long count=0;

    for(int i=n-1; i>=0; i--){
        if((count+c[i])%b[i] != 0){
            count += b[i] - (count+c[i])%b[i];
        }
    }

    cout << count << endl;
}   
