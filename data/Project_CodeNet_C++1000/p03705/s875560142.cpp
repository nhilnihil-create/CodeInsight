#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, a, b;
    cin>>n>>a>>b;
    long long result=0;
    if(n==1) {
        if(a==b) 
          result=1;
        else 
          result=0;
    }
    else if (a > b) 
      result=0;
    else {
        result=(a + b*(n-1))-(a*(n-1) + b)+1;
    }
    cout <<result;
	return 0;
}
