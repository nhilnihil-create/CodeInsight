#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;
int main(){
	int t=0;
	int i, j;
	int d;
	int test;
	int low, high; 
	int number=0;
	long long l;
	long long p;
	char a[65];
	printf("? %lld\n", 10000000000);
	cout.flush();
	t++;
	cin>>a[1];
	if(a[1]=='Y'){
		for(i=1;i<=10;i++){
			p=pow(10, i)-1;
			printf("? %lld\n", p);
			cout.flush();
			t++;
			cin>>a[t];
			if(a[t]=='Y'){
				p=pow(10, i-1);
				printf("! %lld\n", p);
				cout.flush();
				return 0;
			}
		}
	}
	if(a[1]=='N'){
		for(i=0;i<=9;i++){
			p=pow(10, i);
			printf("? %lld\n", p);
			cout.flush(); 
			t++;
			cin>>a[t];
			if(a[t]=='N'){
				d=i;
				break;
			}
		}//确定N的位数d 
		for(i=1;i<=d-1;i++){
			low=0;
			high=9;
			if(i==1) low=1;
			for(j=1;low<high;j++){
				test=(low+high+1)/2;
				l=(number+test*pow(10,d-i))*10;
				printf("? %lld\n", l);
				cout.flush();
				t++;
				cin>>a[t];
				if(a[t]=='Y') high=test-1;
				else low=test;
			}
			number+=low*pow(10,d-i);
		}//对1-d之间的每个i，确定N的左数第i位 
		for(i=d;i<=d;i++){
			low=0;
			high=9;
			if(i==1) low=1;
			for(j=1;low<high;j++){
				test=(low+high)/2;
				l=(number+test*pow(10,d-i))*10;
				printf("? %lld\n", l);
				cout.flush();
				t++;
				cin>>a[t];
				if(a[t]=='Y') high=test;
				else low=test+1;
			}
			number+=low*pow(10,d-i);
		}
	}
	printf("! %d\n", number);
	cout.flush();
	return 0;
}