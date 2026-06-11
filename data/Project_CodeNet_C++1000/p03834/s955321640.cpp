#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<ll>;
using P = pair<ll,ll>;


int main(){
    string s;
    cin >>s;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]==',')s[i]=' ';
    }
    cout <<s<<endl;
    return 0;
}