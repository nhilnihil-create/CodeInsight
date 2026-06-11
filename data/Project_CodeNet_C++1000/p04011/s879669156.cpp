#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k,x,y;
  	cin >> n >> k >> x >> y;
  	int sum=0;
  	if(n-k>0){
    	sum += k*x +(n-k)*y;
    }
  	else{
    	sum += n*x;
    }
  	cout << sum << endl;
}