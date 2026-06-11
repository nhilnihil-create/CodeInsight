#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<ll,ll> pint;


int main(){
    int h,w;
    cin>>h>>w;
    string s[h];
    rep(i,h)cin>>s[i];
    vector<int> res(26);
    rep(i,h)for(auto c : s[i])res[c-'a']++;
    vector<int> cnt(4);
    vector<int> cnt2(2);
    rep(i,res.size()){
        cnt[res[i]%4]++;
    }
    cnt2[0]=cnt[2];
    cnt2[1]=cnt[1]+cnt[3];
    if(h%2&&w%2){
        if(cnt2[1]<=1&&cnt2[0]<=(h-1)/2+(w-1)/2){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    else if(h%2==0&&w%2==0){
        if(cnt2[0]==0&&cnt2[1]==0){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    else{
        if(w%2==1){
            if(cnt2[1]==0&&cnt2[0]<=h/2){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
        if(h%2==1){
            if(cnt2[1]==0&&cnt2[0]<=w/2){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }
}