#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<P,P> PP;
const ll MOD=998244353;
const ll MAX_N=500010;
const ll INF=100100100100100;


int main(){
    int n,a;
    cin>>n>>a;
    vector<int> x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
        x[i]-=a;
    }
    vector<map<int,ll> > mpv(n+1);
    mpv[0][0]=1;
    for(int i=1;i<=n;i++){
        for(auto p:mpv[i-1]){
            int key=p.first;
            ll num=p.second;
            mpv[i][key+x[i-1]]+=num;
            mpv[i][key]+=num;
        }
    }
    cout<<mpv[n][0]-1<<endl;
    
}
