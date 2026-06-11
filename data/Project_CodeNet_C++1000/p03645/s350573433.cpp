#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define rrep(i,n) for(int i=(n);i>=0;--i)
#define ssort(n) sort((n).begin(),(n).end())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define INF 10101010
#define OK cout << "POSSIBLE" << endl
#define NG cout << "IMPOSSIBLE" << endl

int main()
{
    int N,M;
    cin >> N >> M;
    vector<int> a(M),b(M);

    rep(i,M){
        cin >> a[i] >> b[i];
    }
    vector<queue<int>> ship(N+1);
    rep(i,M){
        ship[a[i]].push(b[i]);
    }
    bool result=false;
    while(!ship[1].empty()){
        int val=ship[1].front();
        while(!ship[val].empty()){
            if(ship[val].front()==N){
                result=true;
                break;
            }
            ship[val].pop();
        }
        ship[1].pop();
        if(result)break;
    }

    if(result){
        OK;
    }else{
        NG;
    }

}