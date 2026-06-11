#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <time.h>

using namespace std;
typedef long long int ll;

int main()
{
	string str;
	ll p[12];
	p[0]=1;
	for(int i=1; i<12; i++){
		p[i]=p[i-1]*10;
	}
	for(int i=1; i<=11; i++){
		int d1=0, d2=9;
		while(d1!=d2){
			int mid=(d1+d2+1)/2;
			string str1=str+to_string(mid);
			printf("? %lld\n", stoll(str1));
			fflush(stdout);
			char c;
			scanf(" %c", &c);
			if(c=='Y'){
				d1=mid;
			}else{
				d2=mid-1;
			}
		}
		if(i>1 && d1==9){
			ll x=stoll(str);
			if(x!=p[i-2]){
				string str1=to_string(x-1);
				str1+="90";
				printf("? %lld\n", stoll(str1));
				fflush(stdout);
			}else{
				printf("? %lld\n", 10000000000);
				fflush(stdout);
				char c1;
				scanf(" %c", &c1);
				if(c1=='Y'){
					printf("! %lld\n", p[i-1]);
					fflush(stdout);
					return 0;
				}else{
					printf("? %lld\n", p[i]);
					fflush(stdout);
				}
			}
			char c;
			scanf(" %c", &c);
			if(c=='N'){
				int e1=0, e2=9;
				while(e1!=e2){
					int emid=(e1+e2)/2;
					string str2=str+to_string(emid);
					str2+='0';
					printf("? %lld\n", stoll(str2));
					fflush(stdout);
					char c;
					scanf(" %c", &c);
					if(c=='Y'){
						e2=emid;
					}else{
						e1=emid+1;
					}
				}
				str+=to_string(e1);
				printf("! %lld\n", stoll(str));
				fflush(stdout);
				return 0;
			}else{
				str+='9';
			}
		}else if(i==1 && d1==9){
			printf("? %d\n", 10);
			fflush(stdout);
			char c;
			scanf(" %c", &c);
			if(c=='N'){
				int e1=1, e2=9;
				while(e1!=e2){
					int emid=(e1+e2)/2;
					string str2=to_string(emid);
					str2+='0';
					printf("? %lld\n", stoll(str2));
					fflush(stdout);
					char c;
					scanf(" %c", &c);
					if(c=='Y'){
						e2=emid;
					}else{
						e1=emid+1;
					}
				}
				str+=to_string(e1);
				printf("! %lld\n", stoll(str));
				fflush(stdout);
				return 0;
			}else{
				printf("? %lld\n", 10000000000);
				fflush(stdout);
				char c;
				scanf(" %c", &c);
				if(c=='Y'){
					printf("! %d\n", 1);
					fflush(stdout);
					return 0;
				}else{
					str+='9';
				}
			}
		}else{
			str+=to_string(d1);
		}
	}
	return 0;
}