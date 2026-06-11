#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;
 

int  A(int x){
    if(x>=0)return x;
    else return -x;
}

ll inv(ll x) {
	ll res = 1;
	ll k = N - 2;
	ll y = x%N;
	while (k) {
		if (k & 1)res = (res*y) % N;
		y = (y%N)*(y%N) % N;
		k /= 2;
	}
	return res;
}

unsigned long long popCount64bitB(unsigned long long x) 
{ 
    x = ((x & 0xaaaaaaaaaaaaaaaaUL) >> 1) 
      +  (x & 0x5555555555555555UL); 
    x = ((x & 0xccccccccccccccccUL) >> 2) 
      +  (x & 0x3333333333333333UL); 
    x = ((x & 0xf0f0f0f0f0f0f0f0UL) >> 4) 
      +  (x & 0x0f0f0f0f0f0f0f0fUL); 
    x = ((x & 0xff00ff00ff00ff00UL) >> 8) 
      +  (x & 0x00ff00ff00ff00ffUL); 
    x = ((x & 0xffff0000ffff0000UL) >> 16) 
      +  (x & 0x0000ffff0000ffffUL); 
    x = ((x & 0xffffffff00000000UL) >> 32) 
      +  (x & 0x00000000ffffffffUL); 
    return x; 
} 

bool g[13][13];

int main(void){
    int a,b,h;
    cin>>a>>b>>h;
    cout<<(a+b)*h/2<<endl;
    return 0;
}