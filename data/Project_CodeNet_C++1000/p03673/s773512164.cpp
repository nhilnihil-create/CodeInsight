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
 VI a(n);
 rep(i,n){
     cin >> a.at(i);
 }
 if(n%2==0){
     VI b(n/2);
     VI c(n/2);
     rep(i,n){
         if(i%2==0)b.at(i/2)=a.at(i);
         else if(i%2==1)c.at((i-1)/2)=a.at(i);
     }
     reverse(c.begin(),c.end());
     rep(i,n/2)cout << c.at(i) << " ";
     rep(i,n/2)cout << b.at(i) <<" ";
     cout << endl;
 }
 else{
     VI b((n+1)/2);
     VI c((n-1)/2);
     rep(i,n){
         if(i%2==0)b.at(i/2)=a.at(i);
         else if(i%2==1)c.at((i-1)/2)=a.at(i);
     }
     reverse(b.begin(),b.end());
     rep(i,(n+1)/2)cout << b.at(i) << " ";
     rep(i,(n-1)/2)cout << c.at(i) << " ";
     cout << endl;
 }
}