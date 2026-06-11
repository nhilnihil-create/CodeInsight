#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"yes"<<endl;}else cout<<"no"<<endl;//条件によってYes、Noを出力する
int main(){
    int n;
    cin>>n;
    vector<int> a(n),t(n);
    int amax=0,tmax=0;
    vector<int> l(n),r(n);
    rep(i,n){
        cin>>t[i];
        //tmax=max(tmax,t[i]);
    }
    rep(i,n){
        cin>>a[i];
        //amax = max(amax,a[i]);
    }
    if(n==1){
        if(a[0]==t[0]){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
        return 0;
    }
    l[0]=1;
    for(int i=1;i<n;i++){
        if(t[i] == t[i-1]){
            l[i] = t[i];
        }
        else{
            l[i] = 1;
        }
    }
    r[n-1]=1;
    for(int i=n-2;i>=0;i--){
        if(a[i]==a[i+1]){
            r[i] = a[i];
        }
        else{
            r[i]=1;
        }
    }
    //どちらも上がるポイント=>l==r==1のときのaとtが一致してないとおかしい
    rep(i,n){
        if(l[i]==1 && r[i]==1 && a[i]!=t[i]){
            cout<<0<<endl;
            return 0;
        }
        if(l[i]==1 && t[i]>a[i]){
            cout<<0<<endl;
            return 0;
        }
        if(r[i]==1 && a[i]>t[i]){
            cout<<0<<endl;
            return 0;
        }
    }
    int64_t ans=1;
    rep(i,n){
        //cout<<l[i]<<" ";
        ans = ans * min(r[i],l[i]) % big;
    }
    /*
    cout<<endl;
    rep(i,n){
        cout<<r[i]<<" ";
    }
    cout<<endl;
    */
    cout<<ans<<endl;
}