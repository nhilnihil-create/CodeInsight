#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
//const int PI = acos(-1);
int main(){
	string x;cin>>x;
	int s=0,t=0;
	bool f=true;
	if(x[0]=='T'){
		f=false;
		t++;
	}
	else s++;
	int ans =x.length();
	rep(i,x.length()){
		if(i==0)continue;
		if(f){
			if(x[i]=='T'){
				f=false;
				s--;
				ans-=2;
			}
			else s++;
		}
		else{
			if(x[i]=='S'){
				s++;
				f=true;
			}
			else{
				if(s!=0){
					s--;
					ans-=2;
				}
			}
		}
	}
	cout<<ans<<endl;

}