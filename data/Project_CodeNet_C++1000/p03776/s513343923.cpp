#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MAX_C = 100;
ll Com[MAX_C][MAX_C];
void calc_com() {
    memset(Com, 0, sizeof(Com));
    Com[0][0] = 1;
    for (int i = 1; i < MAX_C; ++i) {
        Com[i][0] = 1;
        for (int j = 1; j < MAX_C; ++j) {
            Com[i][j] = (Com[i-1][j-1] + Com[i-1][j]) ;
        }
    }
}

int main(){
    calc_com();
    
    int n,a,b;
    cin>>n>>a>>b;
    ll v[n];
    rep(i,n) cin>>v[i];
    sort(v,v+n,greater<ll>());
    //平均=でかいものからa個だけとったものの和/A
    ll suma=0;
    for(int i=0;i<a;i++){
        suma+=v[i];
    }
    double ans1=(double)((double)suma/(double)a);

    //a+1個目から見ていってa+1個目が平均と同じ値ならそれを付け加えてもいい
    ll ans2=0;
    ll c=0,ot=0;bool f=true;
    for(int i=0;i<n;i++){
        if(v[a-1]==v[i]){
            c++;
            f=false;
        }
        if(f) ot++;
    }
    if(ot!=0){
        ans2=Com[c][a-ot];
    }
    else{
        for(int i=a;i<=b;i++){
            ans2+=Com[c][i];
        }
    }
    printf("%f\n",ans1);
    cout<<ans2<<endl;
    
    return 0;
}