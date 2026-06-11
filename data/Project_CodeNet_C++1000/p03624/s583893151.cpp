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
    vector<int> c(26,0);
    rep(i,s.size()){
        c[s[i]-'a']++;
    }
    
    rep(i,26){
        if(c[i]==0){
            cout<<(char)(i+'a')<<endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}