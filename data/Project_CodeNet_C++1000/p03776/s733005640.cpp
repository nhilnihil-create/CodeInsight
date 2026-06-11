#include <bits/stdc++.h>
using namespace std;



long long C(long long A,long long B){
  long long ans=1;
  for(int i=0;i<B;i++){
    ans=ans*(A-i)/(i+1);
  }
  return ans;
}


int main() {
 long long N,a,b,c,ans=0;
  long double sum=0;
  cin>>N>>a>>b;
  vector<long long> V(N);
  for(int i=0;i<N;i++){
    cin>>V.at(i);
  }
  sort(V.begin(),V.end());
  reverse(V.begin(),V.end());
  for(int i=0;i<a;i++){
    sum+=V.at(i);
  }
  cout<<fixed<<setprecision(10)<<sum/a<<endl;
  if(V.at(0)==V.at(a-1)){
    c=count(V.begin(),V.end(),V.at(0));
    b=min(b,c);
    for(long long i=a;i<=b;i++){
      ans+=C(c,i);
    }
  
  }
  else{
    c=count(V.begin(),V.end(),V.at(a-1));
    b=count(V.begin(),V.begin()+a,V.at(a-1));
    ans=C(c,b);
  }
  cout<<ans<<endl;
}
