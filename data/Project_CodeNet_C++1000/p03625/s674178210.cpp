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

    vector<ll> A(N);

    for(ll i = 0;i < N;i++)
        cin >> A.at(i);

    ll hako1=0,hako2=0;

    sort(A.begin(),A.end());

    for(ll i = 0;i < N -1;i++){
        if(A.at(i) == A.at(i+1)){
            if(hako1 <= hako2)
                hako1 = A.at(i);
            else
            {
                hako2 = A.at(i);
            }
            i++;
        }
    }    
    

    cout << hako1 * hako2 << endl;
    
}