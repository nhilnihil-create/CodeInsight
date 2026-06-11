#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;
int cnt[100005];
int data[100005];
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(20);
    int N,M,ans = 0;
    cin >> N >> M;
    map<int,int> mp;
    rep(i,N){
        int a;
        cin >> a;
        mp[a]++;
        cnt[a%M]++;
    }
    for(int i=0;i<=M;i++){
        if(i==0){
            ans += cnt[0]/2;
            cnt[0] = 0;
            continue;
        }
        if(i==M-i){
            ans += cnt[i]/2;
            cnt[i] = 0;
            continue;
        }
        //iについてペアとなるのはM-i;
        int t = min(cnt[i],cnt[M-i]);
        ans += t;
        cnt[i] -= t;
        cnt[M-i] -= t;
        //cout << cnt[i] << " " << cnt[M-i] << endl;
        //この操作によって、とりあえずペアは作り終えた
        //後は残った数同士で同じ値があったらペアを作る
        //cout << "i = " << i << " " << cnt[i] << endl;
    }
    for(auto &x:mp){
        int now = x.first;
        int num = x.second;
        if(cnt[now%M]>=2 && num >=2){
            int t = min(cnt[now%M]/2,num/2);
            ans += t;
            cnt[now%M]-=2*t;
        }
    }
    cout << ans << endl;
}
