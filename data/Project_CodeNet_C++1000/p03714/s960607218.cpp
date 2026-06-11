#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<iomanip>
typedef long long int ll;
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define EREP(i,n) for(int i=1;i<=(n);i++)
#define ALL(a) (a).begin(),(a).end()
//#define EVEL 1

#ifdef EVEL
#define DEB(X) cout << #X << ":" <<X<<" " ;
#define TF(f) f ? cout<<"true  " : cout<<"false ";
#define END cout<<"\n";
#define BEG cout<<"D::";
#else
#define DEB(X) {}
#define TF(f) {}
#define END {}
#define BEG {}
#endif
const int MOD = 1000000007;
const ll INF = 50000000000000000;


    ll N,a[500000];
    ll f[500000],b[500000];
    ll ans=-INF;
    ll front,back;
    ll cnt=0;
    priority_queue<ll ,vector<ll>, greater<ll> > F;
    priority_queue<ll> B;
int main(){
    ios_base::sync_with_stdio(false);
    cin>>N;
    REP(i,3*N){
      cin>>a[i];
      if(i<N){
        F.push(a[i]);
        front+=a[i];
      }
    }
    FOR(i,N-1,N*2){

    if(N-1!=i){
        F.push(a[i]);
        front+=a[i];
        front-=F.top();
        F.pop();
    }
      f[cnt]=front;
      cnt++;
      DEB(i)DEB(a[i])DEB(front)DEB(cnt)END
    }
    cnt=0;
    END
    for(int i=N*3-1;N<=i;i--){
      if(i>=2*N){
        B.push(a[i]);
        back+=a[i];
        if(i==2*N){
            b[cnt]=back;
            cnt++;
        }
      }else{
        back+=a[i];
        B.push(a[i]);
        back-=B.top();
        B.pop();
        b[cnt]=back;
        cnt++;
      }
     DEB(i)DEB(a[i])DEB(back)DEB(cnt)END
    }
    END
    REP(i,cnt){
        DEB(i)DEB(cnt)DEB(f[i])DEB(b[cnt-i-1])END
      ans=max(ans,(f[i]-b[cnt-i-1]));
    }
    cout << ans << endl;

    return 0;
}

//ABC 062 D-3N Numbers
