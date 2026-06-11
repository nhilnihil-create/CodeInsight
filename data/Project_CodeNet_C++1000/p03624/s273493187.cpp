#include <bits/stdc++.h>
using namespace std;
  
int main() {
  string S;
  cin >> S;
  
  int bucket[26]={0};//バケット
  
  for(int i=0;i<S.length();i++){
    int tmp= S[i]-'a';
    bucket[tmp]++;
  }
  
  int ans=-1;//答えを格納
  for(int i=0; i<26; i++){
    if (bucket[i]==0){
      ans=i;
      break;
    }
  }
  
  if(ans==-1){
    cout << "None" << endl;
  }else{
    printf("%c",ans+97);
  }
  
  return 0;
      
}