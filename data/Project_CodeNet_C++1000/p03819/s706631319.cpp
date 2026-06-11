#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}

////////////////////////////////////////
const int DAT_SIZE=(1<<20)-1;//調節！！！！！！！！！！！！！！
//セグメント木(0-indexed)！！！！！
ll data[DAT_SIZE],datb[DAT_SIZE];
//[a,b)にxを加算する kは節点の番号で区間[l,r)に対応
void add(int a,int b,int x,int k,int l,int r){
    if(a<=l&&r<=b){
        data[k]+=x;
    }else if(l<b&&a<r){
        datb[k]+=(min(b,r)-max(a,l))*x;
        add(a,b,x,k*2+1,l,(l+r)/2);
        add(a,b,x,k*2+2,(l+r)/2,r);
    }
}
//[a,b)の和を計算する kは節点の番号で区間[l,r)に対応
ll sum(int a,int b,int k,int l,int r){
    if(b<=l||r<=a){
        return 0;
    }else if(a<=l&&r<=b){
        return data[k]*(r-l)+datb[k];
    }else{
        ll res=(min(b,r)-max(a,l))*data[k];
        res+=sum(a,b,k*2+1,l,(l+r)/2);
        res+=sum(a,b,k*2+2,(l+r)/2,r);
        return res;
    }
}
/////////////////////////////////////////////////////////
//ex aにxを加算:add(a,a+1,x,0,0,n);

struct sec{
    int l;
    int r;
    int dis;
};
bool comp(sec a,sec b){
    if(a.dis<b.dis)return true;
    else return false;
}

int main(){
    int n,m;cin>>n>>m;
    sec s[n];
    rep(i,0,n-1){
        cin>>s[i].l>>s[i].r;
        s[i].dis=s[i].r-s[i].l+1;
    }
    sort(s,s+n,comp);
    int ans[m+1];
    int pos=0;
    
    rep(i,1,m){
        while(pos<=n-1&&s[pos].dis<i){
            add(s[pos].l,s[pos].r+1,1,0,0,m+1);
            pos++;
        }
        ans[i]=n-pos;
        for(int j=1;j*i<=m;j++){
            ans[i]+=sum(j*i,j*i+1,0,0,m+1);
        }
        cout<<ans[i]<<endl;
    }
    
    
    return 0;
}