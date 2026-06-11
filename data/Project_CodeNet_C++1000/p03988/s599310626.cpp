#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
#define rep(i,s,n) for(int i = s;i<n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
const ll MOD=1000000007,INF=1ll<<60;
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};
typedef pair<int,pint>P2;
typedef vector<vint>vvint;
 
int N,ma=-1;
int a[101];
int cnt[101];
 
signed main() {
    IOS();
    cin>>N;
    rep(i,0,N){
        cin>>a[i];
        cnt[a[i]]++;
        chmax(ma,a[i]);
    }
    
    if(ma==1){
        if(N!=2){
            cout<<"Impossible"<<endl;
        }else if(a[0]!=1||a[1]!=1){
            cout<<"Impossible"<<endl;
        }else{
            cout<<"Possible"<<endl;
        }
        return 0;
    }
    
    for(int i=ma;i>=(ma+1)/2;i--){
        if(i==(ma+1)/2&&ma%2==0){
            if(cnt[i]!=1){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }else if(i==(ma+1)/2&&ma%2){
            if(cnt[i]!=2){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }else{
            if(cnt[i]<2){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    for(int i=(ma+1)/2-1;i>=0;i--){
        if(cnt[i]){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    cout<<"Possible"<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}