#include <bits/stdc++.h>
using namespace std;

int main(){
long long N,K;
cin>>N>>K;    
vector<int>test(N);
 for(int i=0;i<N;i++){
  cin>>test.at(i);
 }
 sort(test.begin(), test.end(),greater<int>());
 int ans=0;
 for(int i=0;i<K;i++){
  ans=ans+test.at(i);
 }

 
cout<<ans<<endl;
}
