#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    vector <string> a(n),b(m);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,m){
        cin >> b[i];
    }

int ans=0;
rep(l,n-m+1){
    rep(i,n-m+1){
        rep(j,m){
            if(b[j]!=a[j+l].substr(i,m)){
                break;
            }
            if(j==(m-1)){
            ans=1;
            }
        }
    }
}

    if(ans==1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    

    return 0;
}