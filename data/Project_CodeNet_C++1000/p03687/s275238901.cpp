#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<62;
const int INF = 1<<30;
const double PI=acos(-1);
int main(){
	string s;
	int ans=INF;
	int cnt=0;
	cin >>s;
	int last=0;
	int at=0;
	for(char ter='a';ter<='z';ter++){
		last=-1;
		cnt=0;
		//clog << ter << endl;
		for(int i=0;i<s.size();i++){
			
			if(s[i]==ter){
				if(i==0){
					chmax(cnt,0);
				}else{
				chmax(cnt,i-last-1);
			//	clog << i - last - 1 << " ";
				}
			
				last=i;
			}
		}
		if(s[s.size()-1]!=ter){
		chmax(cnt,(int)s.size()-last-1);
		//clog<<s.size()-last-1<<" ";
		}
		//clog<<endl;
		chmin(ans,cnt);
	}
	cout<<ans<<endl;
}