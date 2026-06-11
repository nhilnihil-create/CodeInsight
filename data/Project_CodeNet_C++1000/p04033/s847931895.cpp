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
	ll A,B;
	cin>>A>>B;
	if(A<=0&&B>=0){
		cout<<"Zero"<<endl;
		return 0;
	}
	if(A>0&&B>0){
		cout<<"Positive"<<endl;
	}
	else{
		if((abs(B)-abs(A)+1)%2==0){
			cout<<"Positive"<<endl;
		}
		else{
			cout<<"Negative"<<endl;
		}
	}

}