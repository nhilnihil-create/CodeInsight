#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
int N,C,K;
cin >> N >> C >> K;
int t[100010];
for(int i = 0; i< N;i ++)cin >> t[i];

sort(t,t+N);

int p = 1 ;
int ans = 1;
int x = t[0];
for(int i = 1; i < N; i++){
  if(p == C){
    ans++;
    p = 1;
    x = t[i];
  }
  else if(t[i] > K+x){
    ans++;
    p=1;
    x=t[i];
  }
  else{
    p++;
  }
  
}
  cout << ans << endl;
}

