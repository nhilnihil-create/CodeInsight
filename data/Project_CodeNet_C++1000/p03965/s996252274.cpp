#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffffffffffff
#define N 100010
int a[N];
using namespace std;
int main(void){
	int ans = 0,len, x= 0,y = 0;
	char str[N];
	gets(str);
	len = strlen(str);
	for(int i = 0;i < len;i++){
		if(x==y){
			x++;
			if(str[i]=='p')
			ans--;
		}
		else{
			y++;
			if(str[i]=='g')
			ans++;
		}
	}
	cout<<ans;
}
	