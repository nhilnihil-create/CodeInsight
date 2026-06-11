#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N;
    cin >> N;
    int ans = 0;
    vector<int> tmp;
    rep(i,N) {
        int a;
        cin >> a;
        ans+=a;
        if (a%10!=0) {
            tmp.push_back(a);
        }
    }
    if (ans%10!=0) {
        cout << ans << endl;
    }
    else if (tmp.size()!=0) {
        sort(tmp.begin(),tmp.end());
        ans-=tmp.front();
        cout << ans << endl;
    }
    else {
        cout << 0 << endl;
    }
}

