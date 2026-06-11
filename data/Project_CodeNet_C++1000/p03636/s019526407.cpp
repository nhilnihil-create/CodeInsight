#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;

int main()
{
	string str;
	int n;
	cin>>str;
	n = str.size() - 2;
	cout<<str[0]<<n<<str[n+1]<<endl;
	return 0;
}
