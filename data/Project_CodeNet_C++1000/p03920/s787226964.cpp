#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int loop=(int)sqrt((double)N);
  while((loop*(loop+1))/2<N){
    loop++;
  }
  int over=((loop*(loop+1))/2)-N;
  int max = loop;
  for(loop=1;loop<=max;loop++){
    if(loop==over){
      continue;
    }
    cout << loop << endl;
  }
  return 0;
}
