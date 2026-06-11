#include <bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int>data(3*N);
  for(int i=0;i<3*N;i++){
  	cin>>data.at(i);
  }
  long long ans=0;
  sort(data.begin(),data.end());  
  reverse(data.begin(),data.end());
	for(int i=1;i<2*N;i=i+2){
  	ans=ans+data.at(i);
  }
 cout<<ans<<endl;                     
}
