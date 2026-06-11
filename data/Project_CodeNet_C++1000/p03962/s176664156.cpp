#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
#define all(v) v.begin(),v.end()
#define endl "\n"
#define clr(n, r) memset(n,r,sizeof(n));

void fast() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}


int main() {
    fast();
    int a,b,c;cin>>a>>b>>c;
    int cnt=0;
    if(a!=b&&b!=c&&a!=c)cout<<3;
    else if((a==b&&b!=c)||(a==c&&a!=b)||(b==c&&a!=b))cout<<2;
    else cout<<1;




}