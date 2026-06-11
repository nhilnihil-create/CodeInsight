#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
  string s,sub;
  cin >> s;
  sub=s;
  int n = s.size();
  int csize=1;
  vector<char>S(n);
  for(int i=0; i<n; i++){
   S[i]=s[i];
  }
  sort(S.begin(),S.end());
  for(int i=0; i<n; i++){
   if(i>0 && S[i-1]!=S[i]) csize++;
  }
  
  vector<char>chara(csize);
  vector<int>count(csize);
  int c = 0,x = 0;
  for(int i=0; i<n; i++){
    c++;
    if(S[i]!=S[i+1] || i==n-1){
      chara[x]=S[i];
      count[x]=c;
      x++;
      c = 0;
    }
  }
  
  if(count[0]==n){
   cout << 0 << endl;
   return 0;
  }
  
  int Min=1000;
  for(int i=0; i<csize; i++){
    s=sub;
    int remain=n,motion=0;
    while(remain>0){
    remain=n;
    motion++;
    for(int j=0; j<n-motion; j++){
      if(s[j]!=chara[i] && s[j+1]==chara[i]){
        count[i]++;
        s[j]=chara[i];
      }
    }
     if(s[n-motion]==chara[i]) count[i]--;
     remain=n-count[i]-motion;
    }
    Min=min(Min,motion);
  }
  
  cout << Min << endl;
  
  return 0;
  
}