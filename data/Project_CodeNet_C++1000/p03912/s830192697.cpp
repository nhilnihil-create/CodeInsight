#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>

#define int long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define PB push_back
#define MP make_pair
#define FST first
#define SND second
#define SZ(a) (signed)((a).size())
#define EACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

const int MOD = 1000000007;

#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")"  << " " << __FILE__ << endl;

signed main(void) {
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    VI x(n);
    REP(i,n){
        cin >> x[i];
    }

    int maxx = *max_element(ALL(x));
    VI xl(maxx+1,0);
    VI xm(m,0);
    VI xmp(m,0);
    VI xml(m,0);
    REP(i,n){
        xl[x[i]]++;
        xm[x[i]%m]++;
    }

    FOR(i,1,maxx+1){
        xmp[i%m] += xl[i]/2;
        xml[i%m] += xl[i]%2;
    }

    int ans = 0;

    FOR(i,1,(m-1)/2+1){
        int t = min(xm[i],xm[m-i]);
        if(xml[i]<t){
            xmp[i] -= (t-xml[i]+1)/2;
        }
        if(xml[m-i]<t){
            xmp[m-i] -= (t-xml[m-i]+1)/2;
        }
        ans += t;
    }

    ans += xmp[0] + xml[0]/2;
    if(m%2==0){
        ans += xmp[m/2] + xml[m/2]/2;
        FOR(i,1,m){
            if(i!=m/2){
                ans+=xmp[i];
            }
        }
    }else{
        FOR(i,1,m){
            ans+=xmp[i];
        }
    }





    cout << ans << endl;
    
    return 0;
}