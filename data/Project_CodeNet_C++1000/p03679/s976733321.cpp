#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<deque>
using namespace std;

int main(){
	int x,a,b;
	cin >> x >> a >> b;
	int c=(-1*a)+b;
	
	if(c<=0){
		cout << "delicious" << endl;
	}else if( 0<c && c<=x){
		cout << "safe" << endl;
	}else{
		cout << "dangerous" << endl;
	}
	
	return 0;
}
