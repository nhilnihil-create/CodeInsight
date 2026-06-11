#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
string alp="abcdefghijklmnopqrstuvwxyz";

int main(){
    string S;
    cin >> S;
    int s=S.size();
    if (S[0]!=S[s-1]){
        if (s%2==0){
            cout << "Second" << endl;
        }
        else {
            cout << "First" << endl;
        }
    }
    else {
        if (s%2==0){
            cout << "First" << endl;
        }
        else {
            cout << "Second" << endl;
        }
    }
}