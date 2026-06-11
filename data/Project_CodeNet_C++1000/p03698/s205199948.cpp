#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    string s;
    cin >> s;
    int n = s.size();

    //setとすることで自動的に重複を除いてくれる
    set<char> p;
    rep(i,n){
        p.insert(s.at(i));
    }

    //重複がないならpとsの要素数は一致するはず
    if((int)p.size() == n){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
    
}
