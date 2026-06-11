#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;
#define reverse(s) reverse(s.begin(),s.end())

int main(){
    string t = "abcdefghijklmnopqrstuvwxyz";
    map<char,int> a;
    rep(i,26){
        a[t[i]];
    }

    string s;   cin >> s;
    rep(i,s.size()){
        a[s[i]]++;
    }

    rep(i,26){
        if(a[t[i]]==0){
            cout << t[i] << endl;
            return 0;
        }
    }

    cout << "None" << endl;

    return 0;
}