#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    string s;
    cin >> s;
    ll K;
    cin >> K;
    ll N = s.size();
    rep(i,N){
        if(s[i] == 'a')continue;
        ll manu = 'z'+1- s[i];
        if(manu<=K){
            K -= manu;
            s[i] = 'a';
        }else{
            continue;
        }
    }
    if(K > 0){
        s[N-1] += (K%26);
    }
    cout << s << endl;
}