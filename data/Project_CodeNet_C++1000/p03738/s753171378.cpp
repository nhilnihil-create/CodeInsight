#include <iostream>
#include <cstring>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
 
using namespace std;

typedef long long ll;
typedef long double ld;
#define L(ID) ((ID*2)+1)
#define R(ID) ((ID*2)+2)
#define M(L,R) ((L+R)/2)
#define forr(start,end) for(int i = start; i < end; i++)
#define gap ' '
 
const int MAXN = 100+5;
int weights[MAXN], value[MAXN];

int largest(int a, int b){
	return (a<b)?b:a;
}



int main() {	
	string s, k;
	cin >> s >> k;
	if(s.length() < k.length()){
		cout << "LESS" << endl;
		return 0;
	}
	if(s.length() > k.length()){
		cout << "GREATER" << endl;
		return 0;
	}
	for(int i = 0; i < s.length(); ++i){
		if((s[i] - '0') < (k[i] - '0')){
			cout << "LESS" << endl;
			return 0;
		}
		else if((s[i] - '0') > (k[i] - '0')){
			cout << "GREATER" << endl;
			return 0;
		}
	}
	cout << "EQUAL" << endl;



    return 0;
}	