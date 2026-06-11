#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int x,y;
    cin>>x>>y;
    vector<int> z={1,3,1,2,1,2,1,1,2,1,2,1};
    if (z[x-1]==z[y-1]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
