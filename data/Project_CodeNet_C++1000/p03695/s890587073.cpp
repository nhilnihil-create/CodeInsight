#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main(){
   int N;
   cin>>N;
   int ans=0;
   vector<int>A(N);
   vector<int>B(8);
   int S=0;
   rep(i,8){
       B[i]=0;
   }
   rep(i,N){
       cin>>A[i];
       if(3200<=A[i]){
           S++;
       }
       else{
           B[A[i]/400]++;
       }
   }
    rep(i,8){
        if(B[i]!=0){
            ans++;
        }
    }
    cout<<max(ans,1)<<" "<<ans+S<<endl;
}
