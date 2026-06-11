#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int a,b;
    cin>>a>>b;
    if (a==b) cout<<"Draw"<<endl;
    else if(a==1) cout<<"Alice"<<endl;
    else if(b==1) cout<<"Bob"<<endl;
    else if(a<b) cout<<"Bob"<<endl;
    else cout<<"Alice"<<endl;
}
