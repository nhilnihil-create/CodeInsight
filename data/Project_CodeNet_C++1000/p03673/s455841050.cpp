#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int n; cin>>n;
    vector<int> a(n),b(n);
    rep(i,n) cin>>a[i];

    int ct = 0;
    for(int i=0; i<n; i++){
        if(ct==0){
            b[i/2] = a[n-1 - i];
            ct=1;
        }else{
            b[n-1 - i/2] = a[n-1 -i];
            ct=0;
        }
    }

    for(int i=0; i<n; i++){
        cout << b[i];
        if(i==n-1){
            cout << endl;
        }else{
            cout << " ";
        }
    }
}
