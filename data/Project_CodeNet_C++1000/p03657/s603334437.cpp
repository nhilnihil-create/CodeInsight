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
	int a,b,f=0;
	cin >> a >> b;
	if(a%3==0&&a>=3)f=1;
	if(b%3==0&&b>=3)f=1;
	if((a+b)%3==0&&(a+b)>=3)f=1;
	if(f==1){
		cout << "Possible" << endl;
	}
	else{
		cout << "Impossible" << endl;
	}
}