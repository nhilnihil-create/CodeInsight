#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    ll a,b;
    char op;
    cin>>a>>op>>b;
    if (op=='+') cout<<a+b<<endl;
    else cout<<a-b<<endl;
}
