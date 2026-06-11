#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <cmath>
#define ll long long
using namespace std;

void ask(ll x){
	cout << "? " << x << endl;
	fflush(stdout);
}
bool rec(){
	char x;
	cin >> x;
	return (x == 'Y');
}

int main(){
	//确定N是否为10^k
	bool is10;
	ask(1000000000);
	is10 = rec();
	
	//确定位数
	ll wei = 1;
	if(is10){
		ask(2);
		ll a = 20;
		while(!rec()){
			ask(a);
			a *= 10;
			wei++;
		}
		cout << "! " << a / 20 << endl;
		return 0;
	}
	
	ll l,r,mid;
    for(ll i = 0;i <= 18;i++){
    	ask(pow(10,i));
        if(!rec()){
            l = pow(10,i-1);
            r = pow(10,i);
            break;
        }
    }
 
    while(r - l > 1){
        mid = (l + r) / 2;
        ask(mid * 10);
        if(rec()) r = mid;
        else l = mid;
    }
	
	cout << "! " << r << endl;
	return 0;
}
