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
int digit(int num){
   int cnt=0;
   while(num!=0){
      cnt+=num%10;
      num=num/10;
   }
   return cnt;
}
int main(void){
   int N;
   cin>>N;
   vector<int> A(N);
   for(int i=0;i<N;i++){
      cin>>A[i];
   }
   int ans=0;
   int now=0;
   while(now<N){
      ans++;
      int end=now;
      bool up=false;
      bool down=false;
      while(end+1<N){
         if(A[end+1]>A[end]){
            if(down){
               break;
            }else{
               up=true;
            }
         }
         if(A[end+1]<A[end]){
            if(up){
               break;
            }else{
               down=true;
            }
         }
         end++;
      }
      now=end+1;
   }
   cout<<ans<<endl;
   return 0;
}
