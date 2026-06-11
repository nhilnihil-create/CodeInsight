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
	ll N,A,B,C_A=0,C_B=0;
	string s;
	cin>>N>>A>>B>>s;
	rep(i,N){
		if(s[i]=='a'&&C_A+C_B<A+B){
			cout<<"Yes"<<endl;
			C_A++;
		}
		else if(s[i]=='b'&&C_A+C_B<A+B&&C_B<B){
			cout<<"Yes"<<endl;
			C_B++;
		}
		else{
			cout<<"No"<<endl;
		}
	}
}