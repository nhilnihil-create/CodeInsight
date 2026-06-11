#include <bits/stdc++.h>
using namespace std;

const int N = pow(10,5);

vector<bool> isp(N+1, true);

void sieve() {
  isp[0] = false;
  isp[1] = false;
  for (int i=2; pow(i,2)<=N; i++) {
    if (isp[i]) for(int j=2; i*j<=N; j++) isp[i*j] = false;
  }
}

int main() {
  long long N,a,b=0;
  long long counter=0;
  cin>>N;
  long long counter1=0;
  long long answer=1;
  queue<int>vec;
  // N以下の整数に対して素数判定をしてくれます。
  // nが素数ならば isp(n)=true、そうでなければ isp(n)=false
  sieve();
  // ex. 51から80までの素数を出力
  for (int i=2; i<=N; i++) {if (isp[i]) vec.push(i);
  else continue;}
  a=vec.size();
  counter=vec.front();
  vec.pop();
  for (int i=0; i<a; i++){
  for (int j=1; j<=N; j++){
  b=j;
  while(b%counter==0){
  counter1++;
  b=b/counter;}}
  answer=(answer*(counter1+1))%1000000007;
  counter=vec.front();
  vec.pop();
  counter1=0;}
  cout<<answer<<endl;}