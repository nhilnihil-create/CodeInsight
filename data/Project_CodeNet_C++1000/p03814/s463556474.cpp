#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

struct task{
	int cost;
	int deadLine;
};

bool myComp(task left,task right){
	return (left.deadLine < right.deadLine);
}

int main()
{
	string s;
	int start,end;
	cin>>s;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'A'){
			start = i;
			break;
		}
	}
	for(int i = s.length()-1; i >= 0; i--){
		if(s[i] == 'Z'){
			end = i;
			break;
		}
	}
	cout<<(end - start + 1)<<endl;
	return 0;
}

