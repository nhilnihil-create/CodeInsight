#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <list>
#include <cmath>
#include <stack>
#include <iomanip>

using namespace std;
typedef long long ll;
using Pll = pair<ll,ll>;

const ll INF = 1LL<<60;
const ll MOD = 1000000007;

//cout << fixed << setprecision(10);

int main() {
    ll H, W, N;
    cin >> H >> W >> N;
    vector<ll> A(N),B(N);
    map<Pll,ll> mp;
    ll dx[9] = {0,0,1,1,1,0,-1,-1,-1};
    ll dy[9] = {0,1,1,0,-1,-1,-1,0,1};
    for(int i=0;i<N;i++){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        for(int k=0;k<9;k++){
            ll nx = B[i]+dx[k];
            ll ny = A[i]+dy[k];
            if(nx<1 || nx>=W-1 || ny<1 || ny>=H-1)continue;
            mp[Pll(nx,ny)]++;
        }
    }
    vector<ll> res(10,0);
    ll sum=0;
    for(auto e : mp){
        res[e.second]++;
        //cout << e.first.first << " " << e.first.second <<" " << e.second <<  endl;
    }
    res[0]=(H-2)*(W-2) - mp.size();
    
    for(int i=0;i<10;i++){
        cout << res[i] << endl;
    }

    return 0;
}