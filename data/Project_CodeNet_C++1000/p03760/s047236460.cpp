#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>

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
    string o,e;
    cin >> o >> e;
    string ans;
    
    if(o.size() > e.size()){
        int i=0;
        while(i < e.size()){
            ans += o.at(i);
            ans += e.at(i);
            i++;
        }
        ans += o.at(i);
    }else{
        int i = 0;
        while(i < o.size()){
            ans += o.at(i);
            ans += e.at(i);
            i++;
        }
    }
    
    cout << ans << endl;

}