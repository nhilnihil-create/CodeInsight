#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

const double eps = 1.0e-10;
int N,A,B;

ll COM_list[51][51];
void COM_init(){REP(i,51)REP(j,51)COM_list[i][j]=-1;}
ll COM(int n,int k){
	if(n<0||k<0||k>n)return 0;
	if(COM_list[n][k]!=-1)return COM_list[n][k];
	else if(n==k || k==0){
		COM_list[n][k]=1;
      	return 1;
    }
	else{
    	COM_list[n][k]=COM(n-1,k-1)+COM(n-1,k);
		return COM_list[n][k];
    }
}

// A個以上B個以下選んで平均をK以上にできるか調べる
bool check(double K ,int N,const vector<double> & v){
    vector<double> w(N,0.0);
    REP(i,N)w[i]=v[i]-K;
    vector<double> sw(N+1,0.0);
    REP(i,N)sw[i+1]=sw[i]+w[i];
    bool res=false;
    FOR(i,A,B+1){
        if(sw[i]>-eps){
            res=true;break;
        }
    }
    return res;
}



int main(){
    cin>>N>>A>>B;
    vector<double> v(N);
    REP(i,N)cin>>v[i];
    sort(all(v),greater<double>());
    double ub=1.0e16;
    double lb=0.0;
    double mid;
    for(int cnt=0;cnt<150;cnt++){
        mid=(ub+lb)/2;
        if(check(mid,N,v))lb=mid;
        else ub=mid;
    }
    // 平均の最大は lb
    REP(i,N)v[i]-=lb;
    int cnt1=0;
    int cnt2=0;
	int cnt3=0;
    double sum=0.0;
    REP(i,N){
        sum+=v[i];
        if(sum>eps)cnt1++;
    }
	REP(i,N){if(v[i]==v[cnt1])cnt2++;}
  	REP(i,N){if(v[i]>v[cnt1])cnt3++;}
    // 積まれる荷物の中で価値が最小よりも真に大きい荷物は常に cnt3 個.
    // このとき, 積まれるもののなかで価値最小の荷物を最小で A-cnt3 個, 最大で B-cnt3 個選べる.
    // ただし価値最小の荷物は cnt2 個存在している.
	COM_init();
    ll ans = 0;
    FOR(i,A-cnt3,B-cnt3+1){
        ans += COM(cnt2,i); 
    }
    cout<<fixed<<setprecision(15)<<lb<<endl;
    cout<<(v[cnt1]<1e-7&&v[cnt1]>-(1e-7)?ans:COM(cnt2,A-cnt3))<<endl;
    return 0;
}