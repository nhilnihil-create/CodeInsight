#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll =  long long ;
using P = pair<int,int> ;
using pll = pair<ll,ll>;
constexpr int INF = 1e9;
constexpr ll LINF = 1e18;
constexpr int MOD = 1000000007;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int a = -1,b = -1;
    bool ok = false;
    for(int i=1;i<=2;i++){
        rep(j,n-i){
            if(s[j] == s[j+i]){
                a = j+1;b = j+i+1;
                ok = true;
                break;
            }
        }
        if(ok) break;
    }
    cout << a << " " << b << endl;
    return 0;
}