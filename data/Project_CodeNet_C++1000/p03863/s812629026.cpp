#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
 
using namespace std;
 
const ll MOD = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string s;
    cin >> s;
    int n = s.size();
    if( n%2==0 ^ s[0]==s.back()){
        cout << "Second" << endl;
    }else cout << "First" << endl;
}