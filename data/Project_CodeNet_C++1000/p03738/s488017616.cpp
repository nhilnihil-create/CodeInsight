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
typedef long long ll;

int manLength(int x1,int y1,int x2,int y2){
	return abs(x1-x2) + abs(y1-y2);
}
int main()
{
	string a,b;
	cin>>a;
	cin>>b;
	if(a.length() > b.length()){
		cout<<"GREATER"<<endl;
	}else if(b.length() > a.length()){
		cout<<"LESS"<<endl;
	}else{
		bool equal = true;
		for(int i = 0; i < a.length(); i++){
			int localA,localB;
			localA = a[i] - '0';
			localB = b[i] - '0';
			if( localA > localB){
				cout<<"GREATER"<<endl;
				equal = false;
				break;
			}else if(localA < localB){
				cout<<"LESS"<<endl;
				equal = false;
				break;
			}
		}
		if( equal == true){
			cout<<"EQUAL"<<endl;
		}
	}
	return 0;
}

