#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 100000000000000

int main(){
  int N,x;
  cin>>N>>x;
  if(N==2){
    if(x==2){
      cout<<"Yes"<<endl;
      cout<<1<<endl;
      cout<<2<<endl;
      cout<<3<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }else{
    if(x==1||x==2*N-1){
      cout<<"No"<<endl;
    }else{
      cout<<"Yes"<<endl;
      vector<int> ans(2*N-1);
      if(x==2){
        ans.at(N-1)=2;
        ans.at(N-2)=1;
        ans.at(N-3)=3;
        ans.at(N)=4;
        int number=5;
        for(int i=0;i<2*N-1;i++){
          if(i==N-3||i==N-2||i==N-1||i==N){
            continue;
          }
          ans.at(i)=number;
          number++;
        }
      }else{
        ans.at(N-1)=x;
        ans.at(N-2)=x+1;
        ans.at(N-3)=x-1;
        ans.at(N)=x-2;
        int number=1;
        for(int i=0;i<2*N-1;i++){
          if(i==N-3||i==N-2||i==N-1||i==N){
            continue;
          }
          while(number==x||number==x+1||number==x-1||number==x-2){
            number++;
          }
          ans.at(i)=number;
          number++;
        }
      }
      for(int i=0;i<2*N-1;i++){
        cout<<ans.at(i)<<endl;
      }
    }
  }
}
