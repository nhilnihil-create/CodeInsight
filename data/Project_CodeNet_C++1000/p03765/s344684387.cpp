#include<bits/stdc++.h>
using namespace std;

int main(){
string S,T;; cin >> S >> T;
  //sumS[i]は、S[0],,,S[i]までのBの個数(Aはダブルカウント)
  //sumT[i]は、T[0],,,,T[i]までのBの個数(Aはダブルカウント)
  int m = (int)S.size(); int n = (int)T.size();
  vector<int> sumS(m,0); vector<int> sumT(n,0);
  
  for(int i = 0; i < m; i++){
    if(S[i] == 'A'){ sumS[i]+=2;} else{ sumS[i]++;}
    if(i){ sumS[i] += sumS[i-1];}
  }
  
  for(int j = 0; j < n; j++){
    if(T[j] == 'A'){ sumT[j]+=2;} else{ sumT[j]++;}
    if(j){ sumT[j] += sumT[j-1];}
  }
  
  int q; cin >> q;
  for(int i = 0; i < q; i++){
    int a,b,c,d; cin >> a >> b >> c >> d;
    int cnt1 = sumS[b-1];
     if( a > 1){ cnt1 -= sumS[a-2];}
    int cnt2 = sumT[d-1];
     if( c > 1){ cnt2 -= sumT[c-2];}
    
    if( abs(cnt1-cnt2)%3 == 0){ cout << "YES" << endl;}
    else{ cout << "NO" << endl;} 
  }
  
  return 0;}
 