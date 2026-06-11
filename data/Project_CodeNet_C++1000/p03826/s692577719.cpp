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
    int a,b,c,d;cin>>a>>b>>c>>d;
    cout<<max(a*b,c*d);
}