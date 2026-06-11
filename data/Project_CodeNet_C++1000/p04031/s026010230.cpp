#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main()
{
    int N;
    cin >> N;
    vector<int> a(N);

    rep(i,N){
       cin >> a.at(i);
    }
    int ans=1000000000;
    int tmp=0;
    // cout << a.size() << endl;
    rep2(i,-100,101){
        tmp=0;
        rep(j,N){
            tmp+=(a.at(j)-i)*(a.at(j)-i);
        }
    ans=min(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}