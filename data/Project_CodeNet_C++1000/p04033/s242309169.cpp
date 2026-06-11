#include<bits/stdc++.h>
using namespace std;
#define MAXN 1e6+5;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
  	long long a,b;
  	cin>>a>>b;

  	if(a>0 && b >0) {
  		cout<<"Positive";
  		return 0;
  	}
  	else if(a<=0 && b >=0) {
  		cout<<"Zero";
  		return 0;
  	}
  	else if(a<0 && b < 0) {
  		if((abs(b-a))&1)
  			cout<<"Positive";
  		else
  			cout<<"Negative";
  	}
	return 0;		
}

