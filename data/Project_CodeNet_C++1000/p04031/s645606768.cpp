#include <bits/stdc++.h>
#include <vector>
#include <math.h>
#include <cmath>

using namespace std;

int main(){

 int n,mini=INT_MAX,maxi=INT_MIN,cost = INT_MAX;
 cin>>n;

 int a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    mini= min(mini,a[i]);
    maxi = max(maxi,a[i]);
  }


   for(int i=mini;i<=maxi;i++)
  {
     int sum =0;
     for(int j =0;j<n;j++)
     sum += (a[j] - i) * (a[j] - i);

     if(sum < cost) cost = sum;
   }

   cout<<cost<<endl;

return 0;
}
