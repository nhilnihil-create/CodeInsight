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
   string S;
   cin>>S;
   map<char,bool> judge;
   for(int i=0;i<S.size();i++){
      judge[S[i]]=true;
   }
   bool flag=true;
   if(judge['N']==true&&judge['S']==false){
      flag=false;
   }
   if(judge['S']==true&&judge['N']==false){
      flag=false;
   }
   if(judge['W']==true&&judge['E']==false){
      flag=false;
   }
   if(judge['E']==true&&judge['W']==false){
      flag=false;
   }
   if(flag) cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
   return 0;
}
