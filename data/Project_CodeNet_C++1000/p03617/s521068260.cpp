/////////////////////////////////////////
///       Please Give Me AC!!!!!      ///
/////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main() {
    ll Q, H, S, D;
    cin>> Q >> H >> S >> D;
    ll N;
    cin>> N;

    ll A = min({Q*4, H*2, S});
    cout<< min(A*N, D*(N/2) + A*(N%2)) << endl;
}