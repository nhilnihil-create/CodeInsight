#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
vector<vector<int>> graph;

bool sort_sec(const pair<int,int> &a,const pair<int,int> &b){
   if(a.second<b.second){
      return true;
   }
   return false;
}

void swap(int *a,int *b){
   int temp=*a;
   *a=*b;
   *b=temp;
}

int main(void){
   int N;
   cin>>N;
   vector<long long> A(N),B(N);
   for(int i=0;i<N;i++){
      cin>>A[i]>>B[i];
   }
   long long ans=0;
   for(int i=N-1;i>=0;i--){
      A[i]+=ans;
      if(A[i]%B[i]>=1){
         ans+=(B[i]-A[i]%B[i]);
      }
   }
   cout<<ans<<endl;
   return 0;
}
