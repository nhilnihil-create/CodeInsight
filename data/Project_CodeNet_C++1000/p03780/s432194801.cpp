/********************    I am only one, but still I am one.    **************************************/
/**************    I cannot do everything, but still I can do something.    *************************/
/***   And because I cannot do everything I will not refuse to do the something that I can do.    ***/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define bug1( x ) {cerr << (#x) <<"="<< x << endl;}
#define bug2( x , y ) {cerr << (#x) <<"="<< (x) << "    " << (#y) << "="<< (y) << endl;}
#define bug3( x , y , z ) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl;}
#define bug4( x , y , z , w) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl;}
#define bug5( x , y , z , w ,p) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl;}
#define bug6( x , y , z , w ,p , q) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl;}
#define bugn( x , n ) {cerr << (#x) <<":";for(int i=0;i<n;i++)cerr << x[i] <<"  "; cerr << endl;}
#define bugnm( x , n , m ) {cerr << (#x)<<endl;for(int i=0;i<n;i++){cerr << "Row #" << i<< ":";for(int j=0;j<m;j++)cerr << x[i][j] << "   ";cerr << endl;}}
typedef long long ll;
typedef long double ld;
using namespace std;



bitset<5001>ldp[5002];
bitset<5001>rdp[5002];
int32_t main(){
	IOS
	int n,k;cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ldp[0][0]=ldp[n+1][0]=1;
	for(int i=1;i<=n;i++){
		ldp[i]=ldp[i-1];
		for(int j=k-a[i];j>=0;j--){
			ldp[i][j+a[i]]=ldp[i][j+a[i]]|ldp[i-1][j];
		}
	}
	rdp[0][0]=rdp[n+1][0]=1;
	for(int i=n;i>=1;i--){
		rdp[i]=rdp[i+1];
		for(int j=k-a[i];j>=0;j--){
			rdp[i][j+a[i]]=rdp[i+1][j]|rdp[i][j+a[i]];
		}
	}
	int cnt = 0;
	for(int i=1;i<=n;i++){
		vector<int>l,r;
		for(int j=0;j<k;j++){
			if( ldp[i-1][j] ){
				l.push_back(j);
			}
			if( rdp[i+1][j] ){
				r.push_back(j);
			}
		}
		int ok = 1;
		for(auto x:l){
			ok &=  x + a[i] < k;
		}
		for(auto x:r){
			ok &= x + a[i] <  k;
		}
		
		
		
		//bug3("\n",i,a[i]);
		//bugn(l,(int)l.size());
		//bugn(r,(int)r.size());
		//bug2("Before:",ok);
		for(auto x:l){
			int id = upper_bound(r.begin(),r.end(),k-x-1)-r.begin()-1;
			if( id >= 0 ){
				ok &=  x + r[id] + a[i] < k; 
			   // bug4(x,k-x,r[id],(x + r[id] + a[i] < k));
			}
		}
		
		if( ok ){
			//bug1("YES");
			cnt++;
		}
			
			
	}
	//bug1(cnt);
	cout<<cnt;
	
	
	
}
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
