#include<bits/stdc++.h>
using namespace std;

int main(void){
   int n;
   cin>>n;
   vector<int> a(n);
   for(int i=0;i<n;i++){
      cin>>a[i];
   }
   vector<int> b(n);
   for(int i=0;i<n/2;i++){
      cout<<a[n-1-i*2]<<" ";
      a.erase(a.begin()+(n-1-i*2));
   }
   for(int i=0;i<a.size();i++){
      cout<<a[i]<<" ";
   }
   return 0;
}