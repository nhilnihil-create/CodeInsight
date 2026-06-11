#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  int loop,isTrue=1;
  cin >> a[0];
  int Maxi=a[0],Mini=a[0];
  for(loop=1;loop<N;loop++){
    cin >> a[loop];
    if(Maxi<a[loop]){
      Maxi=a[loop];
    }else if(Mini>a[loop]){
      Mini=a[loop];
    }
  }
  if(Maxi-Mini>1){
    isTrue=0;
  }else if(Maxi-Mini){
    int colorable=Maxi-1;
    //人と完全に違う色を被った猫はMaxi-1匹以下であることが保証される
    //countの値はcolorable以下でなければならない
    int count=0;
    for(loop=0;loop<N;loop++){
      if(a[loop]==Mini)
        count++;
    }
    int colorRem=Maxi-count;
    //人と同じ色を被った猫について、まず「何色が残っているか」を確認する
    //残った色数colorRemと同じ色を被った猫数N-countについて、
    //colorRem*2<=N-countであることが保証される
    if(colorable<count||colorRem*2>N-count)
      isTrue=0;
  }else{
    if(N-Maxi!=1&&N/2<Maxi){
      isTrue=0;
    }
  }
  if(isTrue){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
