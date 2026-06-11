#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    bool ok;
    int remi=n;
    REP(i,n){
        ok = true;
        REP(j,n-i){
            if(s[j+i]!=t[j]){
                ok = false;
                break;
            }
        }
        if(ok){
            remi = i;
            break;
        }
    }
    cout << remi+n << endl;
    return 0;
}