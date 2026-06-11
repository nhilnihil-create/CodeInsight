#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.14159265359

//階乗
ll factorial(ll num){ll sum = 1; for(ll i=1;i<=num;i++) sum*=i; return sum;}
//素数判定
bool isPrime(ll num){if(num<2){return false;}else if(num==2){return true;}else if(num%2==0){return false;} double sqrtNum=sqrt(num);for(int i=3;i<=sqrtNum;i+=2){if(num%i==0)return false;}return true;}

int main(){
  ll a,b;
  cin >> a >> b;
  
  int minus = 0;
  for(int i = a; i <= b; i++){
    if(i<0) minus++;
    if(i==0){
      cout << "Zero" << endl;
      return 0;
    }
  }
  if(minus%2!=0) cout << "Negative" << endl;
  else cout << "Positive" << endl;
}