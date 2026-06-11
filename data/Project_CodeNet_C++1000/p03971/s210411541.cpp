#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
   int N,A,B;
   cin>>N>>A>>B;
   string S;
   cin>>S;
   int cnt=0;
   int abr=0;
   rep(i,S.size()){
       if(S[i]=='c'){
           cout<<"No"<<endl;
       }
       else if(S[i]=='a'){
           if(cnt<A+B){
               cout<<"Yes"<<endl;
               cnt++;
           }
           else{
               cout<<"No"<<endl;
           }
       }
       else{
           if(cnt<A+B&&abr<B){
               cout<<"Yes"<<endl;
               cnt++;
               abr++;
           }
           else{
               cout<<"No"<<endl;
           }
       }
   }
}