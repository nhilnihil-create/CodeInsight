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
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long int ll;

int main()
{
	int n;
	cin>>n;
	int b=0,c=0,d=0;
	rep(i,n){
		int num;
		cin>>num;
		if( num % 4 == 0){
			b++;	
		}else if( num % 2 != 0){
			d++;
		}else{
			c++;
		}
	}
	if( c == 0){
		if( d <= b + 1){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}else{
		if(b >= d){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}

