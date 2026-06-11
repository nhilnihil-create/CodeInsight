#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if (min(b,d)>max(a,c)) cout<<min(b,d)-max(a,c)<<endl;
    else cout<<0<<endl;
}

