#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,k,x,y;
    cin>>n>>k>>x>>y;
    if(n<k)cout<<n*x<<endl;
    else cout<<k*x+(n-k)*y<<endl;

    return 0;
}
