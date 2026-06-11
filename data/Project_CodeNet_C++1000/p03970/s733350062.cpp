#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
string str,cp="CODEFESTIVAL2016";
int dif;
int main(){
	cin>>str;
	for(int i=0;i<16;i++){
		cp[i]==str[i]?dif++:dif+=0;
	}
	cout<<16-dif<<endl;
	return 0;
}
