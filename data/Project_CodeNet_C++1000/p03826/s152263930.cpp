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
#define fore(i,x,y) for(long long i=x;i<y;i++)
typedef long long ll;
using namespace std;
int main()
{
	int A,B,C,D;
	cin>>A>>B>>C>>D;
	if(A*B>C*D){
		cout << A*B << endl;
	}
	else{
		cout << C*D << endl;
	}
}