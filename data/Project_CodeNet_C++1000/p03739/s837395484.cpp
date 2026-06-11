#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<ll,ll> pint;
int main(){
    int n; cin>>n;
    vector<ll> a(n);rep(i,n)cin>>a[i];
    vector<ll> s(n+1);
    vector<ll> sm(n+1);
    rep(i,n){
        s[i+1]=s[i]+a[i];
        sm[i+1]=s[i]+a[i];
    }
    ll ans1 =0;
    ll ans2=0;
    ll cnt1=0;
    ll cnt2=0;
    if(0<s[1]){
        ans2=s[1]+1;
        sm[1]=-1;
        cnt2=-s[1]-1;
    }
    else if(0>s[1]){
        ans1=-s[1]+1;
        cnt1=abs(s[1])+1;
        s[1]=1;
    }
    else{
        sm[1]=-1;
        cnt2=-1;
        s[1]=1;
        ans1 =1;
        cnt1=1;
        ans2=1;
    }
    REP(i,1,n){
        s[i+1]+=cnt1;      
        sm[i+1]+=cnt2;
        //rep(i,n+1) cout<<s[i]<<" ";cout<<"sa"<<endl;
        if(0<=s[i]*(s[i+1])){
            if((i+1)%2==1){
                ans1+=abs(s[i+1])+1;
                cnt1+=abs(s[i+1])+1;
                s[i+1]=1;
            }
            else{
                ans1+=abs(s[i+1])+1;
                cnt1+=-1*abs(s[i+1])-1;
                s[i+1]=-1;
            }
        }
        if(0<=sm[i]*sm[i+1]){
            if((i+1)%2==0){
                ans2+=abs(sm[i+1])+1;
                cnt2+=abs(sm[i+1])+1;
                sm[i+1]=1;
            }
            else{
                ans2+=abs(sm[i+1])+1;
                cnt2+=-1*sm[i+1]-1;
                sm[i+1]=-1;
            }
        }
    //rep(i,n+1) cout<<s[i]<<" ";cout<<endl;
    }
    ll res=min(ans1,ans2);
    cout<<res<<endl;
    //rep(i,n+1) cout<<s[i]<<" ";
}