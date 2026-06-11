#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
#define INF 10101010

int main()
{
    int N;
    
    cin >> N;
    vector<int> a(N);
    rep(i,N)cin >> a[i];

    
    int min=INF;
    int cost;
    ssort(a);
    FOR(i,a[N-1]+1,a[0]){
        cost=0;
        rep(j,N){
            cost+=(a[j]-i)*(a[j]-i);
        }
        if(cost<min){
            min=cost;
        }
    }
    cout << min << endl;
}