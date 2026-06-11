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
   vector<long long> a(3*N);
   for(int i=0;i<3*N;i++){
      cin>>a[i];
   }
   sort(a.begin(),a.end(),greater<long long>());
   long long ans=0;
   int cnt=1;
   for(int i=0;i<N;i++){
      ans+=a[cnt];
      cnt+=2;
   }
   cout<<ans<<endl;
   return 0;
}
