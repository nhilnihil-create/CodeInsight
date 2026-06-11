#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;



int main(){
    int N; cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];
    sort(a.begin(),a.end());
    if(a[0]+1 < a[N-1]){
        cout << "No" << endl;
        return 0;
    }
    if(a[0] == a[N-1]){
        if(a[0] == N-1) cout << "Yes" << endl;
        else if(a[0] <= N/2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else{
        int cnt1 = 0,cnt2 = 0;
        rep(i,N-1){
            if(a[i] != a[i+1]){
                cnt1 = i+1;
                cnt2 = N-cnt1;
                break;
            }
        }
        if(cnt1 < a[N-1] && a[N-1]-cnt1 <= cnt2/2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}