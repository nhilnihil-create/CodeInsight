#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>

#define MOD 1e9+7;
#define INF 1e17+9;
#define PI acos(-1);

using namespace std;

int main(){
	long long a,b,c;
	cin >> a >> b >> c;
	
	if(a%2==0 || b%2==0 || c%2==0){
		cout << "0" << endl;
		return 0;
	}
	
	long long ans=min(a*b,min(b*c,c*a));
	cout << ans << endl;
	return 0;
}
