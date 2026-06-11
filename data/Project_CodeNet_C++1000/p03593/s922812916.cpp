#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int h,w;
    cin>>h>>w;
    map<char,int>mp;
    vector<int>cnt(10010,0);
    rep(i,h){
        string s; cin>>s;
        rep(j,w){
            mp[s[j]]++;
        }
    }
    for(auto&p:mp){
        cnt[p.second]++;
    }
    int g1=0,g2,g3;
    if(h%2==1&&w%2==1)g1=1,g2=h/2+w/2;
    else if(h%2==0&&w%2==1)g2=h/2;
    else if(h%2==1&&w%2==0)g2=w/2;
    else g2=0;
    g3=(h/2)*(w/2);
    while(g1!=0){
        bool ok=false;
        for(int i=1; i<=10000; ++i){
            if(i%4==1||i%4==3){
                if(cnt[i]>0){
                    cnt[i]--,cnt[i-1]++;
                    ok=true;
                    g1--;
                }
            }
        }
        if(!ok){cout<<"No"<<endl; return 0;}
    }
    while(g3!=0){
        bool ok=false;
        for(int i=4; i<=10000; ++i){
            if(i%2==0){
                if(cnt[i]>0){
                    cnt[i]--,cnt[i-4]++;
                    ok=true;
                    g3--;
                }
            }
        }
        if(!ok){cout<<"No"<<endl; return 0;}
    }
    while(g2!=0){
        bool ok=false;
        for(int i=1; i<=10000; ++i){
            if(i%2==0){
                if(cnt[i]>0){
                    cnt[i]--,cnt[i-2]++;
                    ok=true;
                    g2--;
                }
            }
        }
        if(!ok){cout<<"No"<<endl; return 0;}
    }
    cout<<"Yes"<<endl;
    return 0;
}