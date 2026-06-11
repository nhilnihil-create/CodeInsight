#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    string s;
    cin>>s;
    int f,t;
    rep(i,s.size()){
        if(s[i]=='A'){
            f = i;
            break;
        }
    }
    per(i,s.size()){
        if(s[i]=='Z'){
            t = i;
            break;
        }
    }
    
    cout << t-f+1<< endl;
    return 0;
}