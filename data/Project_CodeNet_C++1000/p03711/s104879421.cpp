#include <iostream>
#include <vector>
#include <algorithm>
#include<limits>
#include <cmath>
#include <string>
typedef long long ll;
typedef long l;
using namespace std;
using std::cin ;
#define f1(i,a,b) for(i=a;i<b;i++)
#define f(i,b) for(i=0;i<b;i++)

int main(){
	int test=1,z,i,j,k;
	//cin>>test;
	vector<int> a= {1,3,5,7, 8,10,12}, b ={4, 6,9,11};
	int flag = 0,flag1 = 0,flag2 =0;
	for(z=0;z<test;z++){
		int x,y;
		cin>>x>>y;
		if(x == 2 || y == 2){
			flag = 0;
			break;
		}
		f(i,a.size()){
			if(x == a[i])
				flag1 = 1;
			if(y == a[i])
				flag2 = 1;
		}
		if(flag1 == 1 && flag2 == 1){
			flag = 1;
			break;
		} else {
			flag1 = 0;
			flag2 = 0;
		}
		f(i,b.size()){
			if(x == b[i])
				flag1 = 1;
			if(y == b[i])
				flag2 = 1;
		}
		if(flag1 == 1 && flag2 == 1){
			flag = 1;
			break;
		} else {
			flag1 = 0;
			flag2 = 0;
		}



	}
	if(flag){
		cout<<"Yes";
	} else {
		cout<<"No";
	}

	return 0;
}