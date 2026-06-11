#include<bits/stdc++.h>
using namespace std;

int x ,y;

void process(int n){
	if(n == 5) ++x;
  	if(n == 7) ++y;
}

int main(){
	int a; 
  	for(int i = 0;i < 3 ; ++i){
		cin >> a;
      	process(a);
    }
  	if(x == 2 && y == 1) cout << "YES" << endl;
  	else cout << "NO" << endl;
  return 0;
}