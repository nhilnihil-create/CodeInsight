#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<set>
#include<map>
#include <string>
#include <math.h>
#define cinf(n,x) for(int i=0;i<(n);i++) cin >> x[i];
typedef long long int ll;
using namespace std;
int main(){
  ll n,a,b,c,d; cin >>n>>a>>b>>c>>d;
  for(int p=0;p<n;p++){
    ll Min=p*c-d*(n-1-p);
    ll Max=p*d-c*(n-1-p);
    if(Min<=b-a&&b-a<=Max){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
