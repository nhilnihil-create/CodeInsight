#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int cnt[100010];

int main(){
    int n,m;
    cin>>n>>m;
    rep(i,m){
        int a,b;
        cin>>a>>b;
        cnt[a]++;
        cnt[b]++;
    }

    rep(i,100010){
        if(cnt[i]%2==1){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;

}