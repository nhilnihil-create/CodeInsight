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
	vector<ll>V(3,0);
	cin>>V[0]>>V[1]>>V[2];
	if(V[0]%2+V[1]%2+V[2]%2==0||V[0]%2+V[1]%2+V[2]%2==1||V[0]%2+V[1]%2+V[2]%2==2){
		cout<<"0"<<endl;
	}
	else{
		sort(V.begin(),V.end());
		cout<<V[0]*V[1]<<endl;
	}

}