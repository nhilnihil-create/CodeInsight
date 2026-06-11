#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)

#define ll long long

#define pq(name,type) priority_queue<type> name
#define vec(name,type,length,value) vector<type> name(length,value)
#define vec2(name,type,length,width,value) vector<vector<type>> name(length,vector<type>(width,value));

int main(){
	long long N,M;
  cin >> N >> M;
  if(abs(N - M) >= 2){
    cout << 0 << endl;
    return 0;
  }
  long long n = 1;
  if(N == M){
    n *= 2;
    for(long long i = N;i > 0;i--){
      n *= i;
      n %= 1000000007;
    }
    for(long long i = M;i > 0;i--){
      n *= i;
      n %= 1000000007;
    }
    cout << n << endl;
  }else{
   for(long long i = N;i > 0;i--){
      n *= i;
      n %= 1000000007;
    }
    for(long long i = M;i > 0;i--){
      n *= i;
      n %= 1000000007;
    }
    cout << n << endl;
  }
    
      
  

return 0;
}