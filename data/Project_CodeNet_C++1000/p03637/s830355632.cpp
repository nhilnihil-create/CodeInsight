#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main() {
    int n; cin >> n;
    ll x=0;
    vector<int> c(3,0);
    rep(i,n){
        cin >> x;
        if(x%4==0) c[0]++;
        else if(x%2==0) c[1]++;
        else c[2]++;
    }
    if(c[2]==0){
        cout << "Yes" << endl;
        return 0;
    }
    if(c[0]>0) c[0]++;
    if(c[1]!=0) c[0]--;
    if(c[0]<c[2]){
        cout << "No" << endl;
    }
    else cout << "Yes" << endl;
}