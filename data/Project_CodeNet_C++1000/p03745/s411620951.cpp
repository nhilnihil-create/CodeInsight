#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;

  vector<ll> a(n);
  rep(i,n) cin >> a.at(i);

  int mode; //0:<= 1:>= 2:=
  int count=0;
  rep(i,n){
    while(i+1<n&&a.at(i+1)==a.at(i)) i++;
    if(i+1<n&&a.at(i+1)>=a.at(i)) mode=0;
    else if(i+1<n&&a.at(i+1)<=a.at(i)) mode=1;
    
    //mode:0
    if(mode==0) {while(i+1<n&&a.at(i+1)>=a.at(i)) i++;}
    if(mode==1) {while(i+1<n&&a.at(i+1)<=a.at(i)) i++;}

    count++;
    //cout << i << endl;
  }

  cout << count;
}
