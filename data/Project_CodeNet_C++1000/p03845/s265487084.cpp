#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>
#include <utility>

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

int main(){
    int N,M;
    ll goukei = 0;
    cin >> N;
    vector<ll> T(N);
    for(int i = 0;i < N;i++)
        cin >> T.at(i);
    
    cin >> M;

    vector<int> P(M);
    vector<ll> X(M);

    for(int i = 0;i < M;i++){
        cin >> P.at(i) >> X.at(i);
    }

    for(int i = 0;i < M;i++){
        goukei = 0;
        for(int j = 0;j < N;j++){
            if(j == P.at(i) - 1)
                goukei += X.at(i);
            else
            {
                goukei += T.at(j);
            }
            
        }
        cout << goukei << endl;
    }

    return 0;
    
}