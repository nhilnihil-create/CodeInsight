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
   long long Q,H,S,D;
   cin>>Q>>H>>S>>D;
   long long N;
   cin>>N;
   long long temp1=min(min(Q*4,H*2),S);
   long long temp2=min(min(min(8*Q,4*H),2*S),D);
   cout<<(N/2)*temp2+(N%2)*temp1<<endl;
   return 0;
}
