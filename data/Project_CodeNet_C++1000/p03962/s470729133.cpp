#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    int a,b,c;
    cin>>a>>b>>c;
    if(a==b&&a==c)cout<<1<<endl;
    else if(a==b||b==c||c==a)cout<<2<<endl;
    else cout<<3<<endl;

    return 0;
}

