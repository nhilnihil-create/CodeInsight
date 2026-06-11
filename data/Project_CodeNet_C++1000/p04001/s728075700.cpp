#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;

// str中にあるcを省いて切り詰めるてdestに入れる
// cがスペースの場合、"1 2 3" -> "123"
void ommit(char* src, char c, char* dest){
	int len = strlen(src);
	memset(dest, 0, len+1);
	char *p = dest;
	for(int i=0; i<len; i++){
		if(src[i] != c){
			*p = src[i];
			p++;
		}
	}
}

LL calcStr(char* src){
	char dest[22] = {0};
	ommit(src, ' ', dest);
	char *p;
	long long ret = 0;
	
	p = strtok(dest, "+");
	ret += atoll(p);
	while(p !=NULL){
		p = strtok(NULL, "+");
		if(p != NULL){
			ret += atoll(p);
		}
	}
	return ret;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	int len;
	cin >> s;
	len = (int)s.size();
	string S;
	for(int i=0; i<s.size(); i++){
		S += s[i];
		S += ' ';
	}

	long long ans = 0;
	for(int b = 0; b < (1<<(len-1)); b++){
		string ws = S;
		for(int i=0; i<len-1; i++){
			if(b & (1<<i)){
				ws[i*2+1] = '+';
			}
		}
		ans += calcStr((char*)ws.c_str());
	}
	printf("%lld\n", ans);
	return 0;
}