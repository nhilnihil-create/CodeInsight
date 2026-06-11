#include <iostream>
#include <bits/stdc++.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a,b;
	cin>>a>>b;
	if(a-b>=0){
		cout<<a-b;
	}
	if(a-b<0){
		cout<<0;
	}
	return 0;
}