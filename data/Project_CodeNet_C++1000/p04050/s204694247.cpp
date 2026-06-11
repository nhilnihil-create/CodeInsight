#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N,M;
int A[101];
vector<int>v;
vector<int>vv;
vector<int>ans;
int main(){
    cin>>N>>M;
    REP(i,M){
        cin>>A[i];
        if(A[i]%2==0){
           v.push_back(A[i]);
        }else{
           vv.push_back(A[i]);
        }
    }
    if(M==1){
       if(A[0]==1){
          cout<<1<<endl;
          cout<<1<<endl;
          cout<<1<<endl;
       }else{
          cout<<A[0]<<endl;
          cout<<2<<endl;
          cout<<A[0]-1<<" "<<1<<endl;
       }
    }else if(M==2){
       cout<<A[0]<<" "<<A[1]<<endl;
       if(A[0]==1){
          cout<<1<<endl;
          cout<<A[1]+1<<endl;
       }else{
          cout<<2<<endl;
          cout<<A[0]-1<<" "<<A[1]+1<<endl;
       }
    }else if(vv.size()>=3){
       cout<<"Impossible"<<endl;
    }else{
       if(vv.size()>=1){
          ans.push_back(vv[0]);
       }
       REP(i,v.size()){
          ans.push_back(v[i]);
       }
       if(vv.size()==2){
          ans.push_back(vv[1]);
       }
       
       REP(i,ans.size()){
           cout<<ans[i];
           if(i!=ans.size()-1){
              cout<<" ";
           }else{
              cout<<endl;
           }
       }
       if(ans[0]==1){
          cout<<ans.size()-1<<endl;
       }else{
          cout<<ans.size()<<endl;
          cout<<ans[0]-1<<" ";
       }
       REP(i,ans.size()){
           if(i==0){
              continue;
           }else if(i==ans.size()-1){
              cout<<ans[i]+1<<endl;
           }else{
              cout<<ans[i]<<" ";
           }
       }
    }
    return(0);
}