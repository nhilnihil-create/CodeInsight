#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main() {
    string s = "abcdefghijklmnopqrstuvwxyz";
    string t; cin>>t;
    
    rep(i, (int)s.size()){
        int tmp = t.find(s[i]);
        if(tmp >=0 && tmp<=(int)t.size())continue;
        else {
            cout<<s[i]<<endl;
            return 0;
        }
    }
    cout<<"None"<<endl;
	return 0;
}