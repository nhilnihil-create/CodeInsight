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
   long long N,A,B;
   cin>>N>>A>>B;
   if(A>B){
      cout<<0<<endl;
   }else{
      if(N==1){
         if(A==B){
            cout<<1<<endl;
         }else{
            cout<<0<<endl;
         }
      }else{
         long long mini=A*(N-1)+B;
         long long maxi=A+B*(N-1);
         cout<<maxi-mini+1<<endl;
      }
   }
   return 0;
}
