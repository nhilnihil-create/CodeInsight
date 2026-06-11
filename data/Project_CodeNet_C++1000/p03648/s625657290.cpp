#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int main(){
  ll k;
  cin>>k;
  int n=50;
  ll array[50];
  for(int i=0;i<50;i++) array[i]=49+(k/n);
  for(int i=0;i<(k%n);i++){
    array[i]+=n;
    for(int j=0;j<n;j++){
      if(i!=j) array[j]--;
    }
  }
  cout<<n<<endl;
  for(int i=0;i<n-1;i++) cout<<array[i]<<" ";
  cout<<array[n-1]<<endl;
}
