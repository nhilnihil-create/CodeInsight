#include <bits/stdc++.h>

using namespace std;

int N;
int p[100005];

int main() {

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N;

for(int i=1; i<=N; i++){
  cin>>p[i];
}

int cnt=0;

for(int i=1; i<=N; i++){
  if(p[i]!=i) continue;
  if(i>=2&&p[i-1]==i-1){
    p[i-1]=i;
    p[i]=i-1; 
    cnt++;
  }
  else if(i<=N-1&&p[i+1]==i+1){
    p[i+1]=i;
    p[i]=i+1;
    cnt++;
  }
  else{
    if(i<=N-1){
      p[i+1]=i;
      p[i]=i+1;
      cnt++;
    }
    else if(i>=2){
      p[i-1]=i;
      p[i]=i-1; 
      cnt++;
    }
  }
}

cout<<cnt<<endl;

}
