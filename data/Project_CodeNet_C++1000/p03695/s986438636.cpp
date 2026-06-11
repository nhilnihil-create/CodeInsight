#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
int main(){
	int n;
	int ans1=0;
	int ans2=0;
	cin >>n;
	int bef;
	map<int,int>dis;
	//for(int i=0;i<10;i++){
	//	dis[i]=0;
	//}
	rep(i,n){
		cin>>bef;
		if(bef >=3200){
			dis[8]++;
		}else{
		dis[bef/400]++;
	}
	}
	ans1=dis.size();
	ans2=ans1;
	if(dis[8]!=0){
		ans1--;
		if(ans1==0){
			ans1=1;
		}
		ans2+=dis[8]-1;
	}
	cout<<ans1<<" "<<ans2<<endl;
}