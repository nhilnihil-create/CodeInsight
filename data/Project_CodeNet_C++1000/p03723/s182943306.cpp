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
   long long A,B,C;
   cin>>A>>B>>C;
   long long cnt=0;
   bool flag=false;
   if(A%2!=0||B%2!=0||C%2!=0){
      cout<<cnt<<endl;
      return 0;
   }
   while(!flag){
      int temp1=A;
      int temp2=B;
      int temp3=C;
      A=(temp2+temp3)/2;
      B=(temp1+temp3)/2;
      C=(temp1+temp2)/2;
      if(temp1==A&&temp2==B&&temp3==C){
         cout<<-1<<endl;
         return 0;
      }
      cnt++;
      if(A%2!=0||B%2!=0||C%2!=0){
         flag=true;
      }
   }
   cout<<cnt<<endl;
   return 0;
}
