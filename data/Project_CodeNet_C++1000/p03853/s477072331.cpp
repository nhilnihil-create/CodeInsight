#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int h,w;
    cin>>h>>w;
    vector<string> s(h);
    rep(i,h){
        cin>>s[i];
    }
    rep(i,h){
        cout<<s[i]<<endl;
        cout<<s[i]<<endl;
    }
    
    return 0;
}