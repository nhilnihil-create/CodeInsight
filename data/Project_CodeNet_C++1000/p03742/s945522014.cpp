#include <bits/stdc++.h>

using namespace std;

long long x,y;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> x >> y;
	
	if(x<y){
		swap(x,y);
	}
	
	if((x-y)%3==0){
		if(x-y==0){
			cout << "Brown" << endl;
		}
		else{
			cout << "Alice" << endl;
		}
	}
	else if((x-y)%3==1){
		if(x-y==1){
			cout << "Brown" << endl;
		}
		else{
			cout << "Alice" << endl;
		}
	}
	else{
		cout << "Alice" << endl;
	}
	
	return 0;
}