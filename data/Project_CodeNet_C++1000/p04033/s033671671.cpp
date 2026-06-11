#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	if(a<=0 && 0<=b){
		cout << "Zero" << endl;
	}else if(0<a){
		cout << "Positive" << endl;
	}else if(b<0){
		if((b-a+1)%2==0){
			cout << "Positive" << endl;
		}else{
			cout << "Negative" << endl;
		}
	}
	return 0;
}
