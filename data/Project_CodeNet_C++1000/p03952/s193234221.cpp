#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,x;
  cin>>N>>x;
  if(x==1 || x==2*N-1)
    cout<<"No"<<endl;
  else{
     cout<<"Yes"<<endl;
    if(N==2){
      cout<<1<<endl;cout<<2<<endl;cout<<3<<endl;
    }
    else if(x!=2*N-2){
    set<int>S; for(int i=1;i<=2*N-1;i++)S.insert(i);
      S.erase(x);S.erase(x+1);S.erase(x+2);S.erase(1);
      vector<int>a(2*N-5); int I=0;
      for(auto X:S){a.at(I)=X; I++;}
        for(int i=0;i<N-3;i++)
          cout<<a.at(i)<<endl;
      cout<<x+2<<endl;cout<<1<<endl;cout<<x<<endl;cout<<x+1<<endl;
      for(int i=N-3;i<2*N-5;i++)
        cout<<a.at(i)<<endl;
    
    }else{
        set<int>S; for(int i=1;i<=2*N-1;i++)S.insert(i);
      S.erase(2*N-2);S.erase(2*N-1);S.erase(2*N-3);S.erase(2*N-4);
      vector<int>a(2*N-5); int I=0;
      for(auto X:S){a.at(I)=X; I++;}
        for(int i=0;i<N-3;i++)
          cout<<a.at(i)<<endl;
      cout<<2*N-3<<endl;cout<<2*N-2<<endl;cout<<2*N-1<<endl;cout<<2*N-4<<endl;
      for(int i=N-3;i<2*N-5;i++)
        cout<<a.at(i)<<endl;

    }
  
  }
  return 0;
}