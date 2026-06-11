#include<bits/stdc++.h>
using namespace std;
int main(){
 int n ;
 cin >> n;
 int arr[n+2];
 for(int i=1;i<=n;i++)
    cin >> arr[i];
 int mini = 100000000;
 for(int i=-100;i<=100;i++){
   int cost = 0 ;
   for(int j=1;j<=n;j++){
      int y = i;
      cost+= ((arr[j]-y)*(arr[j]-y));
   }
   mini=min(cost ,mini);
 }
 cout << mini <<endl;
 return 0;
}
