//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,r=0,l=inf; cin>>n;
    vector<int> a(n,0);
    rep(i,n){
        cin>>a[i];
        l=min(l,a[i]);
        r=max(r,a[i]);
    }
    if(r-l==0){
        if((l>=1 && l<=(n/2)) || l==n-1)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl; 
    }
    else if(r-l>1){
        cout<<"No"<<endl;
    }
    else{
        int x=0,y=0;
        rep(i,n){
            if(a[i]==l) y++;
            if(a[i]==r) x++;
        }
        if(x/2>=r-y && r-y>0)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
}