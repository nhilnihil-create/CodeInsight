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
	int w,a,b,c,d;
	cin>>w>>a>>b;
	c=min(a,b);
	d=max(a,b);
	if(c+w<d){
		cout << d-c-w << endl;
	}
	else{
		cout << "0" << endl;
	}

}