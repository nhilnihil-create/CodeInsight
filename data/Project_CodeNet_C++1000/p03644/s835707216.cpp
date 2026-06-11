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
    int N,ans = 0,ma=-1,k,hako;
    cin >> N;

    for(int i = 1;i <= N;i++){
        ans = 0;
        k = i;
        while(k > 0){
            if(k % 2 == 0)
                ans++;
            k /= 2;
        }
        if(ans > ma){
            ma = ans;
            hako = i;
        }

    }

    cout << hako << endl;
}