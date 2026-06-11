#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    string s;
    cin>>s;
    rep(i,s.size()){
        if(i%2)continue;
        cout<<s[i];
    }
    
    cout << endl;
    return 0;
}