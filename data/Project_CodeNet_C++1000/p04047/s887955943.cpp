#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){

ll no;
cin>>no;
ll arr[2*no];
for(int i=0;i<2*no;i++) 
  cin>>arr[i];
 sort(arr,arr+2*no);
 ll sum=0;
 for(int i=0;i<2*no;i+=2) 
   sum+=arr[i];
    cout<<sum;

    return 0;
}
