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
#include <sstream>

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
    int N,P;
    cin >> N >> P;
    vector<int> A(N);

    for(int i = 0;i < N;i++)
        cin >> A.at(i);

    vector<int>kisuu(N),gusuu(N);

    int l = 0,m = 0;
    for(int i = 0;i < N;i++){
        if(A.at(i) % 2 == 0){
            gusuu.at(m) = A.at(i);
            m++;
        }else{
            kisuu.at(l) = A.at(i);
            l++;
        }
        
    }


    if(P == 0){
        ll count = 1;
        for(int i = 1;i < l;i++)
            count *= 2;
        for(int i = 0;i < m;i++)
            count *= 2;

        cout << count << endl;
    }else{
        if(l==0)
            cout << 0 << endl;
        else{
            ll count = 1;
            for(int i = 1;i < l;i++)
                count *= 2;
            for(int i = 0;i < m;i++)
                count *= 2;
            cout << count << endl;
        }
    }

    return 0;

}