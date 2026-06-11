#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    string s;
    cin >> s;
    vector<char> a(s.size());
    rep(i,s.size()){
        a.at(i)=s.at(i);
    }
    sort(a.begin(),a.end());
    bool flag=true;
    rep(i,s.size()-1){
        if(a.at(i)==a.at(i+1))flag=false;
    }
    if(flag) cout << "yes" << endl;
    else cout << "no" << endl;
}