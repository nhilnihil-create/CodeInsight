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
	int X,t;
	cin >> X >> t;
	if(X-t>=0){
		cout << X-t << endl;
	}
	else{
		cout << "0" << endl;
	}
}