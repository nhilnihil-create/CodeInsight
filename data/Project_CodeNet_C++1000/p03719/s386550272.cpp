#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a,b,c;
    cin>>a>>b>>c;
    if(c>=a&&c<=b)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}