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
	string s;
	cin>>s;
	if(s.size()<4){
		cout<<"No"<<endl;
	}
	else{
		if(s[0]=='Y'&&s[1]=='A'&&s[2]=='K'&&s[3]=='I')cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}