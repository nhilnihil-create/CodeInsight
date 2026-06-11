#include <bits/stdc++.h>
 
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
int main(){
    long long ans=1;
int N,a=0,b=0;
cin >>N;
vector <int>T(N);
vector <int>A(N);
vector <int>TT(N);
vector <int>AA(N);
vector <int>AT(N);
for(int i=0;i<N;i++){
    cin >>T[i];
  
}
for(int i=0;i<N;i++){
    cin >>A[i];
  
}
reverse(A.begin(), A.end());
for(int i=0;i<N;i++){
   if(i==0){TT[i]=1;
    if(T[i]>A[N-i-1])ans=0;
   }
   else if(T[i-1]<T[i]){TT[i]=1;
   if(T[i]>A[N-i-1])ans=0;
   }
   else TT[i]=T[i];
}
for(int i=0;i<N;i++){
   if(i==0){AA[i]=1;
    if(T[i]>A[N-i-1])ans=0;
   }
   else if(A[i-1]<A[i]){AA[i]=1;
 if(A[i]>T[N-i-1])ans=0;
   }
   else AA[i]=A[i];
}
reverse(AA.begin(), AA.end());
for(int i=0;i<N;i++){
    AT[i]=min(TT[i],AA[i]);
}
for(int i=0;i<N;i++){
    ans*=AT[i];
    ans%=1000000007;
}

cout <<ans;
}

