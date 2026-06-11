#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

    int main (){
        string s;
        cin >> s;
        vector<int> a(26);
        rep(i,26){
            a[i]=0;
        }
        
        int n=s.size();

        rep(i,n){
            a[s[i]-'a']++;
        }

    string ans ="Yes";

    rep(i,26){
        if(a[i]%2==1){
            ans="No";
        }
    }
    cout << ans << endl;
    }