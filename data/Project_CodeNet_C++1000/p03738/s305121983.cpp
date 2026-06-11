#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    string a,b;
    cin >>a>>b;
    ll co=0;
    if(a.size()>b.size()){
        co=1;
    }
    else if(a.size()<b.size())co=2;
    else {
        for (int i = 0; i < a.size(); ++i) {
            int an=a[i]-'0';
            int bn=b[i]-'0';
            if(an>bn){
                co=1;
                break;
            }
            if(an<bn){
                co=2;
                break;
            }
        }
    }
    if(co==0){
        puts("EQUAL");
    }
    if(co==1){
        puts("GREATER");
    }
    if(co==2){
        puts("LESS");
    }
    return 0;
}

