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
	ll N,ANS=0;
	vector<pair<ll,ll>>V;
	cin>>N;
	rep(i,N){
		pair<ll,ll>a;
		cin>>a.first>>a.second;
		V.push_back(a);
	}
	sort(V.begin(),V.end());
	ANS=ANS+V.back().first-V.front().first+1;
	ANS=ANS+V[0].first-1;
	ANS=ANS+V.back().second;
	cout<<ANS<<endl;
}