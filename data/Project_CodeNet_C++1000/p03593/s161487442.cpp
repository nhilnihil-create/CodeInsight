#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int h,w;cin>>h>>w;
    map<char,int> mp;
    rep(i,h)rep(j,w){
        char c;
        cin>>c;
        mp[c]++;
    }
    if(h%2==0&&w%2==0){
        for(auto& p:mp){
            if(p.second%4!=0){
                cout<<"No"<<endl;
                return 0;
            }
        }
        cout<<"Yes"<<endl;
        return 0;
    }else if(h%2==0||w%2==0){
        int buf=(h%2==0)? h/2:w/2;
        int cou=0;
        for(auto& p:mp){
            if(p.second%4!=0&&p.second%2==0)cou++;
            else if(p.second%2!=0){
                cout<<"No"<<endl;
                return 0;
            }
        }
        if(cou<=buf){
            cout<<"Yes"<<endl;
            return 0;
        }
        else{
            cout<<"No"<<endl;
            return 0;
        }
    }else{
        int cou1=0,cou2=0;
        for(auto& p:mp){
            if(p.second%4==0)continue;
            else if(p.second%2==0&&p.second%4!=0)cou1++;
            else cou2++;
        }
        if(cou1>(w/2+h/2)||cou2!=1){
            cout<<"No"<<endl;
            return 0;
        }
        cout<<"Yes"<<endl;
    }
}