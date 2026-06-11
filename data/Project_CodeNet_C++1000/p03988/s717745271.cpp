#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    //木を端から構築することを考えたら，最大値は2個以上必要
    //最大値をAmaxとすし，最小値をAminとする
    //Amax~Amin+1までは連続で2個以上ないといけない
    //Aminは1個か2個しかありえない．
    //Aminが2個-> Amax=2*Amin-1ならok
    //Aminが1個-> Amax=2*Aminならok
    //ウニの時だけはAminは1個じゃないといけない
    
    string P="Possible",I="Impossible";
    int n;cin>>n;
    vector<int> a(n);
    map<int,int> cnt;
    rep(i,n){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int Amax=*max_element(ALL(a));
    int Amin=*min_element(ALL(a));
    if(n==2){
        if(a[0]==1&&a[1]==1) cout<<P<<endl;
        else cout<<I<<endl;
        return 0;
    }
    //ウニ選別作業
    if(Amin==1){
        if(Amax==2&&cnt[2]==n-1){
            cout<<P<<endl;
        }else{
            cout<<I<<endl;
        }
        return 0;
    }

    if(cnt[Amin]==1){
        bool f=true;
        for(int i=Amin+1;i<=Amax;i++){
            if(cnt[i]<2) f=false;
        }
        if(f&&Amax==2*Amin){
            cout<<P<<endl;
        }
        else{
            cout<<I<<endl;
        }
    }
    else if(cnt[Amin]==2){
        bool f=true;
        for(int i=Amin+1;i<=Amax;i++){
            if(cnt[i]<2) f=false;
        }
        if(f&&Amax==2*Amin-1){
            cout<<P<<endl;
        }
        else{
            cout<<I<<endl;
        }
    }
    else{
        cout<<I<<endl;
    }
    return 0;
}
