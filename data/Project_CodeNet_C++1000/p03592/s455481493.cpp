#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int n,m,k;
    cin>>n>>m>>k;
    
    int ans = 0;
    
    rep(i,n+1)rep(j,m+1){
        ans = i*j + (n-i)*(m-j);
        if(ans==k){
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;
    return 0;
}