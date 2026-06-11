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
	string s,t,k;
	cin >> s >> t >> k;
	s[0]-=32, t[0]-=32,  k[0]-=32;
	cout << s[0]<< t[0] << k[0] << endl;



    return 0;
}	