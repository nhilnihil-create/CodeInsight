#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <stdlib.h>
#include <set>
typedef long long ll;
using namespace std;

int main() {
	string s;
	cin>>s;
	if(s.substr(0,1)=="Y"&&s.substr(1,1)=="A"&&s.substr(2,1)=="K"&&s.substr(3,1)=="I"){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}

	return 0;
}

