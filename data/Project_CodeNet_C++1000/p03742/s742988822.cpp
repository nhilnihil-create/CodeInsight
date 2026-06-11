#include<iostream>
#include<algorithm>
 
using namespace std;

typedef long long ll;
 
ll X, Y;
 
int main(){
  	cin >> X >> Y;
  	if(abs(X - Y) <= 1){
    	cout << "Brown" << endl;
    }else cout << "Alice" << endl;
	return 0;
}