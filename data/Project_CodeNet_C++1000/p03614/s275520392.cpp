#include<iostream>
#include<vector>
using namespace std ;

int main()
{
  int N ;
  cin>>N ;
  vector<int>p(N) ;
  vector<int>S ;
  int count=0 ;
  cin>>p.at(0) ;
  if(p.at(0)==1) count++ ;
  for(int i=1;i<N;i++){
    cin>>p.at(i) ;
    if(i+1==p.at(i)) count++ ;
    else{
      if(count>0) S.push_back(count) ;
      S.push_back(0) ;
      count=0 ;
    }
    if(i==N-1&&i+1==p.at(i)) if(count>0) S.push_back(count);
  }
  int ans=0 ;
  for(int i=0;i<S.size();i++){
    if(S.at(i)>=2){
      if(S.at(i)%2==0) ans+=S.at(i)/2 ;
      else ans+=((S.at(i)+1)/2) ;
    }else if(S.at(i)==1) ans++ ;
  }
  cout<<ans<<endl ;
  
  return 0 ;
}