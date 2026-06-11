#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<int>>;
#define MAX 1000000007

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> x(m),y(m);
    rep(i,m){
        cin >> x[i] >> y[i];
        x[i]--;y[i]--;
    }
    int ans=0;
    vector<ll> num_ball(n,1);
    vector<bool> red_ball(n,false);
    red_ball[0]=true;
    rep(i,m){
        num_ball[x[i]]--;num_ball[y[i]]++;
        if(red_ball[x[i]]==true){
            red_ball[y[i]]=true;
            if(num_ball[x[i]]==0){
                red_ball[x[i]]=false;
            }
        }
    }
    rep(i,n){
        if(red_ball[i]==true){
            ans++;
        }
    }
    cout << ans << endl;

}