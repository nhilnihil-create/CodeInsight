#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
  	bool f=false;
  	while(n!=0){
      if(n%10==9) f= true;
      n/=10;
    }
  	cout << (f?"Yes":"No");
}