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
	string a,b;
	cin >> a >> b;
	if(a[0]==b[0]){
		cout << "H" << endl;
	}
	else{
		cout << "D" << endl;
	}
}