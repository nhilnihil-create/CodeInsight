#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
bool ok(string s){
	int N=s.size();
	if(N%2) return 0;
	return s.substr(0,N/2)==s.substr(N/2,N/2);
}
int count(string s){
	int N=s.size();
	int cnt=0;
	rep(b,1<<N){
		string t;
		rep(i,N) if((b>>i)&1) t+=s[i];
		if(ok(t)) cnt++;
	}
	return cnt;
}
int main(){
	// while(true){
	// 	string s;
	// 	cin>>s;
	// 	cout<<count(s)<<endl;
	// }
	long long N;
	cin>>N;
	N++;
	vector<int> vc;
	while(N){
		vc.pb(N%2);
		N/=2;
	}
	vc.pop_back();
	reverse(all(vc));
	int K=vc.size();
	vector<int> s,t;
	rep(i,K){
		s.pb(i*2);
		t.pb(i*2);
		if(vc[i]==1){
			s.pb(i*2+1);
			t.insert(t.begin(),i*2+1);
		}
	}
	for(int v:t) s.pb(v);
	cout<<s.size()<<endl;
	for(int v:s) cout<<v+1<<" ";
	puts("");
}
