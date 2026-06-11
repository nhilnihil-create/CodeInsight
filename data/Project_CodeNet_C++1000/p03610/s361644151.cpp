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
 
const int MAXN = 2e5+5;

int largest(int a, int b){
	return (a<b)?b:a;
}


int main() {
	string s;
	cin >> s;
	for(int i = 1; i <= s.length(); ++i){
		if(i % 2){
			cout << s[i-1];
		}
	}
	cout << endl;

    return 0;
}	