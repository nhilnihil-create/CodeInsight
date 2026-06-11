#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    string s;
    cin >> s;

    string ans = "";
    REP(i,(int)s.size()){
        if(s[i]=='B'){
            if((int)ans.size()!=0){
                ans.erase((int)ans.size()-1);
            }
        }else{
            ans += s[i];
        }
    }

    cout << ans << endl;
    return 0;

}