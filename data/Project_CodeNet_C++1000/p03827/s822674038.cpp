#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long ll;


int main()
{
	int n;
	cin>>n;
	string str;
	cin>>str;
	int ans = 0;
	int sum = 0;
	rep(i,n){
		if(str[i] == 'I'){
			sum++;
		}else{
			sum--;
		}
		ans = max(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}

