#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;

int gcd(int a, int b) { //最大公約数
  if (b==0) return a;
  else return gcd(b, a%b);
}

int lcm(int a, int b) { //最小公倍数
  return a * b / gcd(a, b);
}


int main()
{
  ll x,a,b;
  cin>>x>>a>>b;
  if(abs(x-a)<abs(x-b)){
    cout<<"A"<<endl;
  }else{
    cout<<"B"<<endl;
  }

  return 0;
}
