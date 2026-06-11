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
	string o,e;
	cin>>o>>e;
	for(int i=0;i<o.size();i++){
			cout << o[i];
			if(o.size()!=e.size()&&i==o.size()-1)break;
			cout << e[i];
	}
	cout << endl;
}