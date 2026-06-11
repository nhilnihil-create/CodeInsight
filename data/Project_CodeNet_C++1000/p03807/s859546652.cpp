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

int gcd(int a,int b){
   if(a%b==0) return b;
   return gcd(b,a%b);
}

int main(void){
   int N;
   cin>>N;
   vector<long long> A(N);
   for(int i=0;i<N;i++){
      cin>>A[i];
   }
   int cnt=0;
   for(int i=0;i<N;i++){
      if(A[i]%2!=0) cnt++;
   }
   if(cnt%2==0) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
   return 0;
}
