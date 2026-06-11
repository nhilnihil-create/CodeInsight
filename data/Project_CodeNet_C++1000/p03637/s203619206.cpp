//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    ll N; cin>>N;
    vector<ll>a(N);
    ll a4=0,a2=0,as=0;
    rep(i,N){
        cin>>a[i];
        if(a[i]%4==0)a4++;
        else if(a[i]%2==0)a2++;
        else as++;
    }
    ll mn =min(a4,as);
    ll cnt=0;
    cnt+=mn*2;
    a4-=mn; as-=mn;
    if(a4==0){
        if(as==0){
            cout<<"Yes"<<endl;
        }
        else if(as==1&&cnt==N-1){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
    else cout<<"Yes"<<endl;
}
