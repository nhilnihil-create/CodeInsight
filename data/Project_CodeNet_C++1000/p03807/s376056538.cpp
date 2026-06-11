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
	ll N,count=0;
	cin>>N;
	rep(i,N){
		ll t;
		cin>>t;
		if(t%2==1)count++;
	}
	if(count%2==1)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}