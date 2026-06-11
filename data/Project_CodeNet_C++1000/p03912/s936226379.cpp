#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <complex>
#include <bitset>
#include <numeric>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n) ;++(i))
#define REPN(i,a,n) FOR((i),(a),(a)+(n))
#define FOR(i,a,b) for(int (i)=(a); (i)<(b) ;++(i))
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
#define DBG(a) cerr<<(a)<<endl;
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;  typedef pair<LL, LL> PLL; typedef vector<LL> VLL;
const LL LINF=334ll<<53; const int INF=15<<26; const LL MOD=1E9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<int> x(n),mod(m),p(m);
    map<int,int> cnt[100010];
    REP(i,n){
        cin >> x[i];
        mod[x[i]%m]++;
        cnt[x[i]%m][x[i]/m]++;
        if(cnt[x[i]%m][x[i]/m]%2==0){
            p[x[i]%m]++;
        }
    }
    int ans=0,ad;
    REP(i,(m+2)/2){
        if(i==0){
            ad=mod[i]/2;
            ans+=ad;
            mod[i]-=ad*2;
        }else if(m%2==0&&i==m/2){
            ad=mod[i]/2;
            ans+=ad;
            mod[i]-=ad*2;
        }else{
            ad=min(mod[i],mod[m-i]);
            ans+=ad;
            mod[i]-=ad;
            mod[m-i]-=ad;
        }
    }
    REP(i,m){
        ans+=min(mod[i]/2,p[i]);
    }
    cout << ans <<endl;




    return 0;
}
