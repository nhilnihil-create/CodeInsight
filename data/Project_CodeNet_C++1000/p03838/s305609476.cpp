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


int main()
{
	int x1,x2;
	cin>>x1>>x2;
	if(x1 == x2){
		cout<<0<<endl;
	}else if(x1 == 0 && x2 > 0){
		cout<<x2<<endl;
	}else if(x1 > 0 && x2 == 0){
		cout<<x1 + 1<<endl;
	}else if(x1 == 0 && x2 < 0){
		cout<<abs(x2)+1<<endl;
	}else if(x2 == 0 && x1 < 0){
		cout<<abs(x1)<<endl;
	}else if(x1 >= 0 && x2 >= 0 && x2 > x1){
		cout<<x2 - x1<<endl;
	}else if( x1 >= 0 && x2 >= 0 && x2 < x1){
		cout<<x1 - x2 + 2<<endl;
	}else if((x1 >= 0 && x2 < 0) || (x1 < 0 && x2 >= 0)){
		cout<<abs(abs(x1)-abs(x2))+1<<endl;
	}else if(x1 < 0 && x2 < 0 && x2 < x1){
		cout<<abs(x2)-abs(x1) + 2<<endl;
	}else{
		cout<<abs(abs(x2)-abs(x1))<<endl;
	}
	return 0;
}

