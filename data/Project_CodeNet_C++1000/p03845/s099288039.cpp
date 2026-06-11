#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
 int n;
 cin >> n;
 VI t(n);
 rep(i,n){
   cin >> t.at(i);
 }
 int m;
 cin >> m;
 VI p(m),x(m);
 rep(i,m){
   cin >> p.at(i) >> x.at(i);
 }
 rep(i,m){
   ll sum=0;
   rep(j,n){
     if(j==p.at(i)-1){
       sum+=x.at(i);
     }
     else sum+=t.at(j);
   }
   cout << sum << endl;
 }
}