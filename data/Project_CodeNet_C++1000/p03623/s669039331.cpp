#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int x,a,b;
    cin>>x>>a>>b;
    a=abs(x-a),b=abs(x-b);
    if (a<b) cout<<"A"<<endl;
    else cout<<"B"<<endl;
}
