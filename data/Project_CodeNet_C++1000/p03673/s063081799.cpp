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
    ll N;
    cin >> N;
    vector<ll> kisuu(N/2 + 1);
    vector<ll> V(N),gusuu(N/2);

    for(ll i = 0;i < N;i++)
        cin >> V.at(i);
    
    for(ll i = 0;i < N;i++){
        if(i % 2 == 0){
            kisuu.at(i/2) = V.at(i);
        }else{
            gusuu.at(i/2) = V.at(i);
        }
        
    }

    if(N % 2 == 0){
        reverse(gusuu.begin(),gusuu.end());
        for(ll i = 0;i < gusuu.size();i++)
            cout << gusuu.at(i) << " ";
        for(ll i = 0;i < kisuu.size() -1;i++)
            cout << kisuu.at(i) << " ";

        cout << endl;
    }else{
        reverse(kisuu.begin(),kisuu.end());
        for(ll i = 0;i < kisuu.size();i++)
            cout << kisuu.at(i) << " ";
        for(ll i = 0;i < gusuu.size();i++)
            cout << gusuu.at(i) << " ";

        cout << endl;

    }
}