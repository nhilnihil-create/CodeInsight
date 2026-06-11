#include<iostream>
#include<math.h>
using namespace std;

#define ll long long
int main(){


int n;

cin>>n;
int arr[n];
double sum=0;
for(int i=0;i<n;i++)
{
    cin>>arr[i];
    sum+=arr[i];
}

ll floormid, ceilmid;
ceilmid=ceil(sum/n);
floormid= floor(sum/n);


ll ans1=0, ans2=0;
for(int i=0;i<n;i++)
{   
ans1+= pow(arr[i]-ceilmid,2);
ans2+= pow(arr[i]-floormid,2);

}

cout<<min(ans1, ans2);
  
}