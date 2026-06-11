#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 800000000
#define MAX 1000

int main(){
  string S;
  int K;
  cin>>S>>K;
  int n=S.size();

  int i=0;
  int j=0;
    while(i<K){
    int x=S.at(j)-'a';
    if(j==n-1){
      int y=(x+K-i)%26;
      S.at(j)=(char)('a'+y);
      break;
    }
    if((26-x)%26<=K-i){
      i+=(26-x)%26;
      S.at(j)='a';
      j++;
    }else{
      j++;
    }
  }
  cout<<S<<endl;
}
