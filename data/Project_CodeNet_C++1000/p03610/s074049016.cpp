#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    string s; cin >> s;
    string t;
    
    for(int i = 0; i < s.size(); i+=2){
        t.push_back(s[i]);
    }

    put(t);
}