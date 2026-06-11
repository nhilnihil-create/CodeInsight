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
	ll A,B,C,D,N,MIN;
	cin>>A>>B>>C>>D>>N;
	A=A*4;
	B=B*2;
	MIN=min(A,B);
	MIN=min(MIN,C);
	if(D>=MIN*2){
		cout<<MIN*N<<endl;
	}
	else{
		if(N%2==0){
			cout<<D*(N/2)<<endl;
		}
		else{
			cout<<D*(N/2)+MIN<<endl;
		}
	}
}