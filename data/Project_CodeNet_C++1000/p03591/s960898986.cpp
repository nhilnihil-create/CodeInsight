#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<pair<int,int>>>;
#define INF 1000000000000000000
#define MOD 1000000007

int main(){
  string S;
  cin>>S;

  if(S.size()<4){
    cout<<"No"<<endl;
  }else{
    if(S.at(0)=='Y'&&S.at(1)=='A'&&S.at(2)=='K'&&S.at(3)=='I'){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
}
