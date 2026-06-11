#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 800000000
#define MAX 1000

int main(){
  string S;
  cin>>S;
  string T="CODEFESTIVAL2016";
  int count=0;
  for(int i=0;i<16;i++){
    if(S.at(i)!=T.at(i)){
      count++;
    }
  }
  cout<<count<<endl;
}
