#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char s[12];
	cin>>s;
	for(int i=0;i<12;i++){
		cout<<s[i];
		if(i==3){
			cout<<" ";
		}
	}
	cout<<"\n";
	return 0;
}