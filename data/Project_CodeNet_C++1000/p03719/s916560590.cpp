#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
typedef long long ll;
typedef vector<ll> vll;
const int inf = 1e9;
int main(){
    int a,b, c;
    cin >> a >> b >> c;
    cout << ((c >= a && c <= b)?"Yes":"No") << endl;
    return 0;
}