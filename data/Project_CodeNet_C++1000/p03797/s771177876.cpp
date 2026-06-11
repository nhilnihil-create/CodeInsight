#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,m;
    cin >> n >> m;
    long long ans;
    if(2*n==m){
        ans=n;
    }
    else if(2*n>m){
        ans=m/2;
    }
    else{
        ans=(m+2*n)/4;
    }
    cout << ans << endl;
}