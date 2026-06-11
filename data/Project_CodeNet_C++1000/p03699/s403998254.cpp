#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long int ll;

int main()
{
	int n;
	cin>>n;
	int *s = new int[n];
	int minNum = 101;
	int sum = 0;
	rep(i,n){
		cin>>s[i];
		sum += s[i];
		if(s[i] % 10 != 0){
			minNum = min(minNum,s[i]);
		}
	}
	if( sum % 10 == 0 && minNum == 101){
		cout<<0<<endl;
	}else if( sum % 10 == 0 && minNum != 101){
		cout<<sum-minNum<<endl;
	}else{
		cout<<sum<<endl;
	}
	return 0;
}

