#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    vector<bool>ch(26,true);
    string s;cin >>s;
    ll n=s.size();
    for (int i = 0; i < n; ++i) {
        ch[s[i] - 'a'] = false;
    }
    for (int i = 0; i < 26; ++i) {
        if(ch[i]){
            cout <<(char)(i+'a')<<endl;
            return 0;
        }
    }
    puts("None");
    return 0;
}