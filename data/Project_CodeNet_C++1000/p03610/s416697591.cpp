#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define ll long long

int main(){
    string s; cin >> s;
    vector<char> t(s.size());
    int res=0;
    rep(i,s.size()){
        if(i%2==0){
            t[res] = s[i];
            res++;
        }
    }
    t.resize(res);
    rep(i,t.size()){
        cout << t[i];
    }
    cout << endl;

}