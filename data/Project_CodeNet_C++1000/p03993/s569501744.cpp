#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define BIL ((ll)1e9)
#define MOD ((ll)1e9+7)
#define INF (1LL<<60)           //1LL<<63でオーバーフロー
#define inf (1<<29)             //1<<29でオーバーフロー

int main(int argc,char* argv[]){
    int n;
    cin >> n;

    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        int nowval=a[i];
        if(nowval==-1)continue;
        if(a[nowval]==i){
            ans++;
            a[i]=-1;
            a[nowval]=-1;
        }
    }

    cout << ans << endl;

    return 0;
}
