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
    int N,goukei=0;
    cin >> N;
    vector<int> s(N);
    bool fla = false;

    for(int i = 0;i < N;i++)
        cin >> s.at(i);
    
    sort(s.begin(),s.end());

    for(int i = 0;i < N;i++)
        goukei += s.at(i);

    if(goukei % 10 == 0){
        fla = true;
        for(int i = 0;i < N;i++){
            if((goukei - s.at(i)) % 10 != 0){
                goukei -= s.at(i);
                fla = false;
                break;
            }
        }
    }

    if(fla)
        cout << 0 << endl;
    else
    {
        cout << goukei << endl;
    }
    
    
    
}