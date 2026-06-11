#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i = 0; i < N; i++){
    cin >> a.at(i);
  }
  int p[8]= {0};
  int q = 0;
  for(int i = 0; i< N; i++){
  if(a.at(i)<400){
    p[0]++;
  }
  else if(a.at(i)<800){
    p[1]++;
  }
  else if(a.at(i)<1200){
    p[2]++;
  }
  else if(a.at(i)<1600){
    p[3]++;
  }
  else if(a.at(i)<2000){
    p[4]++;
  }
  else if(a.at(i)<2400){
    p[5]++;
  }
  else if(a.at(i)<2800){
    p[6]++;
  }
  else if(a.at(i)<3200){
    p[7]++;
  }
  else{
    q++;
  }
}
int ans = 0;
for(int i = 0; i<8;i++){
  if(p[i]!=0){
    ans++;
  }
}
if(ans==0){
  if(q>0){
  cout << 1 << " " << q << endl;
}
else{
  cout << 0 <<" "<< 0 << endl;
}
}
else{
  cout << ans<< " " << ans+q << endl;
  }
}

