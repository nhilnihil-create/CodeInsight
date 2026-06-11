#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;



int main(){
    string s; cin >> s;
    int n = s.size();
    if(s[0] != s[n-1]){
        if((n-2) % 2 == 0){
            cout << "Second" << endl;
        }
        else cout << "First" << endl;
    }
    else{
        if((n-2) % 2 == 0){
            cout << "First" << endl;
        }
        else cout << "Second" << endl;
    }
}
