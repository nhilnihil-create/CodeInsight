#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  if((n==1&&a!=b)||a>b){
    cout << 0 << endl;
  }else{
    cout << (n-2)*(b-a)+1 << endl;
  }
}