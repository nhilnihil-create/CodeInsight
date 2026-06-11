#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    string s;
    cin >> s;
    vector<char> ss(s.size()+1);
    ss.at(4)=' ';
    rep(i,4)ss.at(i)=s.at(i);
    for(int i=5;i<s.size()+1;i++){
        ss.at(i)=s.at(i-1);
    }
    rep(i,s.size()+1){
        cout << ss.at(i);
    }
    cout << endl;
}
