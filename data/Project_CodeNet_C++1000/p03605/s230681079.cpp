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
	string str;
	cin >> str;
	if(str[0]=='9'||str[1]=='9'){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}