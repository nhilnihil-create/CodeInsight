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
int main()
{
	ll N,t,ANS=0;
	vector<ll>V;
	cin>>N;
	rep(i,3*N){
		cin>>t;
		V.push_back(t);
	}
	sort(V.begin(),V.end());
	reverse(V.begin(),V.end());
	for(ll i=1;i<=2*N;i=i+2){
		ANS=ANS+V[i];
	}
	cout<<ANS<<endl;
}