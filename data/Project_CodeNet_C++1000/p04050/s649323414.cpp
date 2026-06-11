#include <bits/stdc++.h>
using namespace std;
#define oo 1000000
#define mod 1000000007
const int N = 200010;
int n , m , a;
vector< int > v1 , v2 , v3 , v4;

void answer(){
	for(int i = 0 ;i < (int)v3.size();i++){
		if(i) putchar(' ');
		printf("%d",v3[i]);
	}
	printf("\n%d\n",(int)v4.size());
	for(int i = 0 ;i < (int)v4.size();i++){
		if(i) putchar(' ');
		printf("%d",v4[i]);
	}
	puts("");
	exit(0);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0 ;i < m;i++){
		scanf("%d",&a);
		if(a & 1)
			v1.push_back(a);
		else
			v2.push_back(a);
	}
	if((int)v1.size() == 0){
		v3 = v2;
		v4.push_back(1);
		for(int i = 0 ;i < (int)v2.size();i++){
			if(i == (int)v2.size() - 1){
				v4.push_back(v2[i] - 1);
			}
			else
				v4.push_back(v2[i]);
		}
		answer();
	}
	else if((int)v1.size() == 1){
		v3 = v2;
		v3.push_back(v1[0]);
		if((int)v3.size() == 1 && n == 1){
			v4.push_back(1);
			answer();
		}
		v4.push_back(1);
		for(int i = 0 ;i < (int)v3.size();i++){
			if(i == (int)v3.size() - 1){
				if(v3[i] != 1) v4.push_back(v3[i] - 1);
			}
			else
				v4.push_back(v3[i]);
		}
		answer();
	}
	else if((int)v1.size() == 2){
		v3.push_back(v1[0]);
		for(int i = 0 ;i < (int)v2.size();i++) v3.push_back(v2[i]);
		v3.push_back(v1[1]);
		for(int i = 0 ;i < (int)v3.size();i++){
			if(i == 0)
				v4.push_back(v3[i] + 1);
			else if(i == (int)v3.size() - 1){
				if(v3[i] != 1)
					v4.push_back(v3[i] - 1);
			}
			else
				v4.push_back(v3[i]);
		}
		answer();
	}
	else
		puts("Impossible");
	return 0;
}