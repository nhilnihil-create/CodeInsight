#include<bits/stdc++.h>
using namespace std;
int main(){
	char s[20],coppy[20]="CODEFESTIVAL2016";
	scanf("%s",s);
	int a=16;
	for(int i=0;i<=15;i++){
			if(s[i]==coppy[i])
			a--;
	}
	cout << a;
	return 0;
}