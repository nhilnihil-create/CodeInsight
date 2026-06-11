#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#include <iomanip>
//cout << fixed << setprecision(20) << *** << endl;
#define rep(i,N) for(int i=0;i<(int)N;++i)
typedef long long ll;
using namespace std;

vector<vector<ll>>bits(ll N){
	vector<vector<ll>> V;
	for(int t=0;t<(1<<N);t++){
		vector<ll> vv;
		for(int i=0;i<N;i++){
			if(t&(1<<i))vv.push_back(i);
		}
		V.push_back(vv);
	}
	return V;
}

int main()
{
	ll N;
	set<ll>st;
	cin>>N;
	rep(i,N){
		ll t,size;
		cin>>t;
		size=st.size();
		st.insert(t);
		if(st.size()==size){
			st.erase(t);
		}
	}
	cout<<st.size()<<endl;
}