#include<iostream>
using namespace std;
#include<cmath>

int main(){
 int n,k;
 cin >> n >> k;
 int a[n];
 for(int i=0;i<n;i++)
      cin >> a[i];
 int t=0;
 for(int i=0;i<n;i++){
   t+=min(abs(a[i]-0)*2,abs(a[i]-k)*2);
 }
 cout << t;
 return 0;
}
