#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define Inf 1 << 20
#define MInf -(1 << 20)
 
#define rep(i,n) for(int i = 0;i < (int)(n);i++)
#define Rep(i,n,m) for(int i = (int)(n); i < (int)(m);i++)
#define rrep(i,n) for(int i = (int)(n - 1); i > -1;i--)
#define RRep(i,n,m) for(int i = (int)(n - 1); i > (int)(m);i--)
#define trav(a, x) for(auto& a : x)
 
#define ALL(V) (V).begin(),(V).end()
#define SORT(V) sort(ALL(V))
#define REVERSE(V) reverse(ALL(V))
#define RSORT(V) SORT(V);REVERSE(V)
 
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
#define yes(n) cout << ((n) ? "yes" : "no") << endl;

int main()
{
    string s;
    cin >> s;
    char s1 = s[0];
    char s2 = s[s.size() - 1];
    cout << s1 << s.size() - 2 << s2 << endl;
}
