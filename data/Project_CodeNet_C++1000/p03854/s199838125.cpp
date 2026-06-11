#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    string s;cin>>s;
    string t;
    while(s.size()){
        if(s.size()<5)break;
        
        t = s.substr(s.size()-5,5);
        if(t=="dream" || t=="erase"){
            rep(i,5)s.pop_back();
            continue;
        }
        
        if(s.size()<6)break;
        t = s.substr(s.size()-6,6);
        if(t=="eraser"){
            rep(i,6)s.pop_back();
            continue;
        }
        
        
        if(s.size()<7)break;
        t = s.substr(s.size()-7,7);
        if(t=="dreamer"){
            rep(i,7)s.pop_back();
            continue;
        }
        
        break;
    }
    
    puts(s.size()==0?"YES":"NO");
    
    return 0;
}