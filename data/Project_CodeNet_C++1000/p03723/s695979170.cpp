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

	if(V[0]%2==1||V[1]%2==1||V[2]%2==1){
		cout<<"0"<<endl;
		return 0;
	}
	else if(V[0]==V[1]&&V[1]==V[2]){
		cout<<"-1"<<endl;
		return 0;
	}

	ll count=0;
	
	for(;;){
		if(V[0]%2==1||V[1]%2==1||V[2]%2==1)break;
		ll o,p,q;
		o=V[0];
		p=V[1];
		q=V[2];
		V[0]=p/2+q/2;
		V[1]=o/2+q/2;
		V[2]=o/2+p/2;
		count++;
	}
	cout<<count<<endl;
}