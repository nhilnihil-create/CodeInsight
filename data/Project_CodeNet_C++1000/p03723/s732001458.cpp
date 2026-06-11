#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>

using namespace std;

const long long MOD = 1000000007;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	int cnt=0,temp_a=a,temp_b=b,temp_c=c;
	while(1){
		if(a%2!=0 || b%2!=0 || c%2!=0){
			break;
		}
		if((a%2==0 && b%2==0 && c%2==0)&&(a==b && b==c)){
			cout << "-1" << endl;
			return 0;
		}
		temp_a=(b+c)/2;
		temp_b=(c+a)/2;
		temp_c=(a+b)/2;
		a=temp_a;
		b=temp_b;
		c=temp_c;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}