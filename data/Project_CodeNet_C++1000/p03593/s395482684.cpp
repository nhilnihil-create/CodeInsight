#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int h,w;
    cin>>h>>w;
    map<char,int> mp;
    rep(i,h){
        rep(j,w){
            char c;
            cin>>c;
            mp[c]++;
            mp[c]%=4;
        }
    }

    int cnt2=0,cnt13=0;
    for(auto p : mp){
        if(p.second==2) cnt2++;
        if(p.second==1 || p.second==3) cnt13++;
    }

    if(h%2==0 && w%2==0){
        if(cnt2>0 || cnt13>0){
            cout<<"No"<<endl;
            return 0;
        }
    }
    else if(h%2==1 && w%2==1){
        if(cnt13>1 || cnt2>(w/2+h/2)){
            cout<<"No"<<endl;
            return 0;
        }
    }
    else{
        if(w%2!=0) swap(w,h);
        if(cnt2>w/2 || cnt13>0){
            cout<<"No"<<endl;
            return 0;
        }
    }


    cout<<"Yes"<<endl;
}