#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define INF 1000000000000
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define seq vector
signed main(){
    int N,M,s,t,c;
    cin >> N >> M;

    vector< vector<int> > table(N,vector<int>(N,1e9));
    vector< vector<int> > edges(M,vector<int>(0));
    for(int i=0;i<N;i++){
        table[i][i] =0;
    }
    for(int i=0;i<M;i++){
        cin >> s >> t >> c;
        s--;t--;
        table[s][t] =c;
        table[t][s] =c;
        edges[i].push_back(s);
        edges[i].push_back(t);
        edges[i].push_back(c);
    }

    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++ ){
                if(table[i][j] > table[i][k]+table[k][j])
                    table[i][j] = table[i][k]+table[k][j];
            }
        }
    }
    int count =0;
    for(auto i : edges){
        s=i[0];
        t=i[1];
        c=i[2];

        if (table[s][t] != c)
            count++;
    }
    cout << count << endl;


    
}