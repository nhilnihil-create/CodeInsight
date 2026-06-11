#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    int n;cin>>n;
    int a[n+1];rep1(i,n)cin>>a[i];
    int cnt=0;
    rep1(i,n){
        if(i==a[a[i]])cnt++;
    }
    co(cnt/2);
}