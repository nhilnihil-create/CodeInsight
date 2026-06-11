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
#define ALL(x) x.begin(),x.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    ll a = A;

    map<int,bool>mpa;

    for(int i = 0;i < a;i++)
        mpa[i] = false;

    bool fla = false;

    while(true){
        if(a % B == C){
            fla = true;
            break;
        }else if(mpa[a%B] == true){
            break;
        }else{
            mpa[a%B] = true;
            a += A;    
        }
    }

    if(fla)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}