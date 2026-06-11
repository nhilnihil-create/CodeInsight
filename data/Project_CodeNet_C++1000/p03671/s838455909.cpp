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
	vector<int>vec(3,0);
	cin >> vec[0] >> vec[1] >> vec[2];
	sort(vec.begin(),vec.end());
	cout << vec[0]+vec[1] << endl;
}