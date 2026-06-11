#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int cnt[100010];
int main()
{
    int N,M;
    cin >> N >> M;
    rep(i,M){
        int a,b;
        cin >> a >> b;
        --a;--b;
        cnt[a]++;cnt[b]++;
    }
    bool ok=true;
    rep(i,N){
        ok&=(cnt[i]%2==0);
    }
    if(ok)cout << "YES";
    else cout << "NO";
    cout << endl;
    
    return 0;
}
