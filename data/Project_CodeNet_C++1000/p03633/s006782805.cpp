#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define SP << " " 
#define LLi long long int

using namespace std;

LLi gcd(LLi a, LLi b) {
	if(a<0) a=b;
	if(b<0) b=a;
    if (b == 0) return a;
    return gcd(b, a%b);
}

LLi lcm(LLi a, LLi b) {
    return a/gcd(a, b)*b;
}

int main(){

	LLi n, m, tmp;
	cin>> n >> m;
  
  	rep(i, n-1){
      cin>> tmp;
      m=lcm(m, tmp);
    }
     
  	cout<< m <<endl;
  
  	return 0;
}