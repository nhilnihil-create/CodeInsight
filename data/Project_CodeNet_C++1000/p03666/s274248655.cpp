#include<bits/stdc++.h>

#define FOR(i, a, b) for(int(i)=(a);(i)<(b);(i)++)
#define REP(i, n) FOR((i), 0, (n))

#define RFOR(i, b, a) for(int(i)=(b); (i)>=(a); (i)--)
#define RREP(i, n) FOR((i), (n), 0)

#define pb push_back
#define mp make_pair 

using namespace std;

const int INF=INT_MAX/4;
const int MOD=1000000007;
const double EPS=1e-14;

const bool debug_flag=true;

void debug(string str){
	if(debug_flag){
		cout<<str<<endl;
	}
}

void debugs(string str){
	if(debug_flag){
		cout<<str;
	}
}

long n=1, a=1, b=1, c=1, d=1;

bool check(int m){
	return m*c-(n-1-m)*d<=b-a && b-a<=m*d-(n-1-m)*c;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout.precision(10);

	cin>>n>>a>>b>>c>>d;
	for(int i=0; i<n-1; ++i){
		if(check(i)){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;

	return 0;
}

