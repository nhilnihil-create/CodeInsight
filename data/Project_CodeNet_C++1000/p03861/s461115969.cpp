#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
long long work(long long c,long long n);
int main(){
	long long a,b,x;
      cin >> a >> b >> x;
  long long total = work(b,x) - work(a - 1,x);
  cout << total << endl;
return 0;
}

long long work(long long c,long long n){
  if(c < 0){
    return 0;
  }else{
    return c / n + 1;
}
}