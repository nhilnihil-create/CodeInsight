#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  string S;
  cin>>S;
  int N=S.size();
  if(N%2==1){
    puts("No");
    return 0;
  }
  map<char,char> A;
  A['q']='p',A['p']='q',A['b']='d',A['d']='b';
  for(int i=0;i<N/2;i++)
    if(A[S[i]]!=S[N-1-i]){
      puts("No");
      return 0;
    }
  puts("Yes");
}