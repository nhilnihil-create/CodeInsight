#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    string s;
    map<int,int> m;
    cin >> s;
    rep(i,s.size()){
        m[s[i]]++; 
    }
    if(m['N']>0){
        if(m['S']==0){
            cout << "No"<<endl;
            return 0;
        }
    }
    if(m['S'] > 0) {
        if(m['N'] == 0) {
            cout << "No" << endl;
            return 0;
        }
    }

    if(m['E'] > 0) {
        if(m['W'] == 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    if(m['W'] > 0) {
        if(m['E'] == 0) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes"<<endl;
}