#include <bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
void cntr(){ cout << 0 << "\n"; }
int main(){
int N; cin >> N; int L=N-1;
unsigned long long T[N], A[N], ans=1;
for(int i=0; i<N; i++){ cin >> T[i]; }  
for(int i=0; i<N; i++){ cin >> A[i]; }  
if(N==1){ if(A[0]==T[0]){ cout << 1 << "\n"; }else{ cntr(); } }
else if(A[0]<T[0] || (A[0]>A[1] && A[0]!=T[0])){ cntr(); }
else if(A[N-1]>T[N-1] || (T[N-1]>T[N-2] && A[N-1]!=T[N-1])){ cntr(); }
else{  
for(int i=1; i<N-1; i++){ 
  if(T[i-1]==T[i] && A[i]==A[i+1]){ ans=(ans*min(T[i], A[i]))%MOD; }
  else if(T[i-1]<T[i] && A[i]>A[i+1]){ if(A[i]!=T[i]){cntr(); return 0;} }
  else if(T[i-1]<T[i]){ if(A[i]<T[i]){cntr(); return 0;} }
  else if(A[i]>A[i+1]){ if(A[i]>T[i]){cntr(); return 0;} }
}
cout << ans << "\n";
}
}