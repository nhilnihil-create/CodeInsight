#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <cstdint>
#include <istream>
#include <sstream>
#include <cctype>
#include <functional>
#include <iomanip>
#define rep(i,N) for(ll i=0;i<N;i++)
#define disp(a) cout << a << endl;
#define PI 3.1415926535897932384626433
//cout << fixed << setprecision(20) << ** << endl;
typedef long long ll;
using namespace std;
double deg2rad(double degree)
{
    return degree * PI / 180.0000000000;
}
int main()
{
	ll N;
	vector<ll>V;
	string s,t;
	cin>>N>>s>>t;
	rep(i,N){
		ll F=0;
		rep(j,s.size()){
			if(s[j]==t[j]){
				F++;
			}
			else F=0;
		}
		V.push_back(F);
		s.erase(s.begin());
	}
	sort(V.begin(),V.end());
	cout<<2*N-V.back()<<endl;
}