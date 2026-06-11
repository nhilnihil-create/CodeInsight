#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
   string S;
   cin>>S;
   int cnt=0;
   rep(i,S.size()-1){
       if(S[i]!=S[i+1]){
           cnt++;
       }
   }
   cout<<cnt<<endl;
    }
