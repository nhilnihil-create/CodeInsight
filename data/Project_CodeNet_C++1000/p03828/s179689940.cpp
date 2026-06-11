#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define INF 1000000000000
#define MOD 1000000007
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<int> E(1001,-1);
  for(int i = 2; i <= 1000; i++){
    if(E.at(i)==-1){
      E.at(i)=i;
      for(int j = 2; i*j <= 1000; j++){
        if(E.at(i*j)==-1)E.at(i*j)=i;
      }
    }
  }
  map<int,int> divisor;
  for(int i = 2; i <= n; i++){
    int tmp = i;
    while(E.at(tmp)!=tmp){
      divisor[E.at(tmp)]++;
      tmp/=E.at(tmp);
    }
    if(divisor.count(tmp))divisor[tmp]++;
    else divisor[tmp] = 1;
  }
  ll res = 1;
  for(auto p : divisor){
    int count = p.second;
    count++;
    res*=count;
    res%=MOD;
  }
  cout<<res<<endl;
}