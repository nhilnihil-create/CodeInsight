#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int n,l,t;
	cin>>n>>l>>t;
	vector< pair<int,int> > ant;
	for(int i=0;i<n;i++){
		int x,w;
		cin>>x>>w;
		if(w==2)w=-1;
		ant.pb( mp(x,w) );
	}
	vector<int> last;
	for(int i=0;i<n;i++){
		int za = ( ant[i].first + t*ant[i].second + l*inf) % l;
		last.pb(za);
	}
	//for(int i=0;i<last.size();i++)cout<<last[i]<<" "; cout<<endl;
	int onepos = -1;
	if( ant[0].second == 1){
		int cnt = 0;
		vector<int> gyaku;
		for(int i=1;i<n;i++){
			if( ant[0].second != ant[i].second ){
				int sa = ant[i].first - ant[0].first;
				gyaku.pb(sa);
			}
		}
		int tm = 2 * t;
		cnt += (tm/l)*gyaku.size();
		tm = tm%l;
		cnt += upper_bound( gyaku.begin(), gyaku.end(), tm-1 ) - gyaku.begin();
		//cout<<"cnt"<<cnt<<endl;
		onepos = cnt%n;
	}
	else{
		int cnt = 0;
		vector<int> gyaku;
		for(int i=1;i<n;i++){
			if( ant[0].second != ant[i].second ){
				int sa = l + ant[0].first - ant[i].first;
				gyaku.pb(sa);
			}
		}
		reverse( gyaku.begin(), gyaku.end() );
		int tm = 2 * t;
		cnt += (tm/l)*gyaku.size();
		tm = tm%l;
		cnt += upper_bound( gyaku.begin(), gyaku.end(), tm-1 ) - gyaku.begin();
		//cout<<"cnt"<<cnt<<endl;
		onepos = (n-cnt)%n;
	}
	int good = last[0];
	sort(last.begin(),last.end());
	int start;
	if( ant[0].second==1 )start = lower_bound( last.begin(), last.end(), good ) - last.begin();
	else start = upper_bound( last.begin(), last.end(), good ) - last.begin() - 1;
	for(int i=0;i<n;i++){
		cout<<last[ (start-onepos+n+i)%n ]<<endl;
	}
	return 0;
}