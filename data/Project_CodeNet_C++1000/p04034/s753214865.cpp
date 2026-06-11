#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<ll>())
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

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> x(m),y(m);
    vector<int> ball(n,1);
    vector<bool> red_ball(n,false);
    int a,b;
    rep(i,m){
        cin >> a >> b;
        a--;b--;
        x[i]=a;y[i]=b;
    }

    red_ball[0]=true;
    rep(i,m){
        ball[y[i]]++;
        ball[x[i]]--;
        if(red_ball[x[i]]==true){
            if(red_ball[y[i]]==false){
                red_ball[y[i]]=true;
            }
            if(ball[x[i]]==0)
                red_ball[x[i]]=false;
        }

    }
    int count=0;
    rep(i,n){
        if(red_ball[i]==true){
            count++;
        }
    }
    cout << count << endl;
}