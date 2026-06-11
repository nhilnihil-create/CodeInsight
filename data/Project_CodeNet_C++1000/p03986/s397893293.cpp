#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
  string x;cin >>x;
  ll ans=0;
  char key='S';
  vector<ll>cnt;
  ll now=0;
    for (int i = 0; i < x.size(); ++i) {
        if(key==x[i]){
            now++;
        }
        else {
            cnt.push_back(now);
            if(key=='S')key='T';
            else key='S';
            now=1;
        }
    }
    cnt.push_back(now);
    if(cnt.size()%2==1)cnt.push_back(0);
    ll s=0,t=0;
//    for (int i = 0; i < cnt.size(); ++i) {
//        cout <<cnt[i]<<" ";
//    }
//    cout <<endl;
    for (int i = 0; i < cnt.size(); i+=2){
        s+=cnt[i];
        t=cnt[i+1];
        ll mint=min(s,t);
        s-=mint;
        t-=mint;
//        cout <<s <<" "<<t<<endl;
        ans+=t;
//        cout <<ans <<endl;
        t=0;
    }
    ans+=s;
    cout <<ans <<endl;
   return 0;
}

