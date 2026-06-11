#include<iostream>
using namespace std;
typedef long long ll;
#define fr(i,n) for(int i=0;i<n;i++)

int main(){
  ll n,a[100010],b[100010],s=0,k;
  cin>>n;
  fr(i,n){
    cin>>a[i];
    s+=a[i];
  }
  if(s%((n*(n+1))/2)>0){
    cout<<"NO"<<endl;
    return 0;
  }
  k=s/((n*(n+1))/2);
  fr(i,n) b[i]=a[i]-a[(i+1)%n]+k;
  bool f=0;
  fr(i,n) if(b[i]<0 || b[i]%n>0) f=1;
  cout<<(f?"NO":"YES")<<endl;
}