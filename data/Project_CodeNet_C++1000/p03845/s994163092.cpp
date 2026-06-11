#include<iostream>
using namespace std;
#define ll long long
#define for(i,n) for(int i=0;i<(int)n;i++)
int main(){
int n;
  cin>>n;
  int arr[n];
  int sum = 0;
  for(i,n){cin>>arr[i];sum+= arr[i];}
  int m;
  cin>>m;
  int p,x;
  int d = sum;
  for(i,m){
    cin>>p>>x;
    sum -= arr[p-1];
    sum += x;
    cout<<sum<<endl;
    sum = d;
  }
  return 0;
}