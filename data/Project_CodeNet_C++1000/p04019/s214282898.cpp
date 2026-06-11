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
	ll N=0,S=0,E=0,W=0;
	string s;
	cin>>s;
	rep(i,s.size()){
		if(s[i]=='N')N=1;
		if(s[i]=='S')S=1;
		if(s[i]=='E')E=1;
		if(s[i]=='W')W=1;
	}
	if((N==1&&S==0)||(N==0&&S==1)){
		cout<<"No"<<endl;
		return 0;
	}
	if((E==1&&W==0)||(E==0&&W==1)){
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;

}