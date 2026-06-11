#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,N) for(int i=0; i<N; i++){ ;
int main() {
   string s;
   cin>>s;
   for(int i=0; i<s.size(); i++){
       if(s.at(i)==','){
           s.at(i)=' ';
       }
   }
   cout<<s<<endl;
}
