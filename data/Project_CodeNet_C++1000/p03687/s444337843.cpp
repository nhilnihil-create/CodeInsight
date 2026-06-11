#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
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
const double PI = acos(-1);

int main(){
	string s;cin>>s;
	set<char>se;
	rep(i,s.length()){
		se.insert(s[i]);
	}
	if(se.size()==1){
		cout<<0<<endl;
		return 0;
	}
	int ans =INF;
	for(char wa :se){
		int cnt =0;
		string t,w=s;
		while(1){
			cnt++;
			rep(i,w.length()-1){
				if(w[i]==wa){
					t.push_back(w[i]);
				}
				else
				{
					t.push_back(w[i+1]);
				}
			}
			bool f=true;
			rep(i,t.length()){
				if(t[i]!=wa){
					f=false;
				}
			}
			if(f){
				break;
			}
			w=t;
			t="";
		}
		ans=min(ans,cnt);
	}
	cout<<ans<<endl;
}