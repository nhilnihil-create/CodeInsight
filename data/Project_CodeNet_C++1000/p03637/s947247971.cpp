#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N;
   cin>>N;
   vector<long long> a(N);
   for(int i=0;i<N;i++){
      cin>>a[i];
   }
   int count=0;
   int temp=0;
   for(int i=0;i<N;i++){
      if(a[i]%4==0) count+=2;
      else if(a[i]%2==0) temp++;
   }
   int count2=0;
   if(temp>=2){
      count2=temp-1;
   }
   int ans=count+count2;
   if(ans>=N-1){
      cout<<"Yes"<<endl;
   }else{
      cout<<"No"<<endl;
   }
   return 0;
}