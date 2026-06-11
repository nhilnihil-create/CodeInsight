#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long ll;


int main()
{
	string str;
	cin>>str;
	for(int i = 0 ; i < str.length(); i++){
		if( i % 2 == 0){
			cout<<str[i];
		}
	}
	cout<<endl;
	return 0;
}

