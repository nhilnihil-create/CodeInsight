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
	int n;cin>>n;
	string s;cin>>s;
	rep(a,2)rep(b,2){
		string now;
		if(a==1)now.push_back('W');
		else now.push_back('S');
		if(b==1)now.push_back('W');
		else now.push_back('S');
		rep2(i,1,n){
			if(now[i]=='S'){
				if(s[i]=='o'){
					now.push_back(now[i-1]);
				}
				else now.push_back((now[i-1]=='W' ? 'S':'W'));
			}
			else{
				if(s[i]=='x'){
					now.push_back(now[i-1]);
				}
				else {
					now.push_back((now[i-1]=='W' ? 'S':'W'));
				}
			}
		}

		if(now[0]!=now[n])continue;
		if(now[0]=='S'){
			if(s[0]=='x'&&now[n-1]==now[1])continue;
			else if(s[0]=='o'&&now[n-1]!=now[1])continue;
		}
		if(now[0]=='W'){
			if(s[0]=='x'&&now[n-1]!=now[1])continue;
			else if(s[0]=='o'&&now[n-1]==now[1])continue;
		}
		now.erase(now.begin()+n);
		cout<<now<<endl;
		return 0;
	}
	cout<<-1<<endl;
}