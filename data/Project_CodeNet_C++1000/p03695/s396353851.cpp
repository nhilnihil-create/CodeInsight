#include <bits/stdc++.h>
using namespace std;
 
int rate(int x){
  if(x>=1 && x<=399){
    return 0;
  }else if(x>=400 && x<=799){
    return 1;
  }else if(x>=800 && x<=1199){
    return 2;
  }else if(x>=1200 &&x<=1599){
    return 3;
  }else if(x>=1600 && x<=1999){
    return 4;
  }else if(x>=2000 && x<=2399){
    return 5;
  }else if(x>=2400 && x<=2799){
    return 6;
  }else if(x>=2800 && x<=3199){
    return 7;
  }else{
    return 8;
  }
}

int main() {
  int N;
  cin >> N;
  
  vector<int> count(9,0);
  
  vector<int> a(N);
  for(int i=0; i<N; i++){
    cin >> a[i];
    
    int color;
    color=rate(a[i]);
    count[color]++;
  }
  
  int answer=0;
  for(int i=0; i<8;i++){
    if(count[i]!=0){
      answer++;
    }
  }
  
  if(answer==0){
    cout << "1"<<" ";
  }else{
    cout << answer<<" ";
  }
    
   
  cout <<answer+count[8] << endl;   
  
}