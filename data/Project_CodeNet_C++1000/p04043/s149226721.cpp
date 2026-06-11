#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=1e6+5;
vector<ll> V;
int pre[maxn];
int main() {
    vector<int> N(3);
    for(int i=1;i<=3;i++) cin>>N[i-1];
    sort(N.begin(),N.end());
    cout<<((N[0]==5&&N[1]==5&&N[2]==7)?"YES":"NO")<<endl;
    return 0;
}