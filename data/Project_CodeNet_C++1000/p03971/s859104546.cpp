#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
using pp=pair<int,pair<int,int>>;
#define MAX 200003
#define MOD 1000000007
#define INF 1000000000000000000

int main(){
  int N,A,B;
  string S;
  cin>>N>>A>>B>>S;
  int count1=0,count2=0;
  for(int i=0;i<N;i++){
    if(S.at(i)=='a'){
      if(count1<A+B){
        count1++;
        cout<<"Yes"<<endl;
      }else{
        cout<<"No"<<endl;
      }
    }else if(S.at(i)=='b'){
      if(count1<A+B&&count2<B){
        count1++;
        count2++;
        cout<<"Yes"<<endl;
      }else{
        cout<<"No"<<endl;
      }
    }else{
      cout<<"No"<<endl;
    }
  }
}
