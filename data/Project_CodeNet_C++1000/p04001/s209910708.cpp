#include <iostream>
#include <iomanip>
#include<vector>
#include <algorithm>
#include <queue>
#include<string>
#include <map>
#include <cmath>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <set>
#include <bitset>
typedef long long ll;
typedef long double ld;
#define PI  3.14159265358979323846

#define REP(i,s,n)for(ll i=s;i<(n);++i)
#define rep(i,n) REP(i,0,n)
using namespace std;
string S;

vector<string>A;


int main() {
    cin >> S;
    ll ans = 0;
    ll num = S.length();
    rep(bit,1<<(num-1)) {
        ll count = 0;
        string tmpS = S;
        for (ll j = 0; j < num - 1;++j) {
            if (bit&(1<<j)) {
                tmpS.insert(j+1+count, "+");
                count++;
            }
        }
        A.push_back(tmpS);
    }
    rep(i,A.size()) {
        ll tmpAns = 0;
        rep(j,A[i].length()) {
            if (A[i][j]!='+') {
                tmpAns *= 10;
                tmpAns += (A[i][j]-'0');
                if (j== A[i].length()-1) {
                    ans += tmpAns;
                }
            }
            else if(A[i][j] == '+'){
                ans += tmpAns;
                tmpAns = 0;
            }
            
        }
    }
    cout << ans << endl;
    return 0;
}