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
   long long a,b;
   cin>>a>>b;
   if(a>0&&b>0){
      cout<<"Positive"<<endl;
   }else if(a<0&&b<0){
      if((b-a+1)%2==0){
         cout<<"Positive"<<endl;
      }else{
         cout<<"Negative"<<endl;
      }
   }else if(a<=0&&b>=0){
      cout<<"Zero"<<endl;
   }
   return 0;
}
