#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<int>a(N);
  for(int i=0;i<N;i++)
    cin>>a.at(i);
  sort(a.begin(),a.end());
  bool x=true;
  if(!(a[0]*2-a[N-1]==0 || a[0]*2-a[N-1]==1))
    cout<<"Impossible"<<endl;
  else if(a[0]*2-a[N-1]==0){
  map<int,int>M;
    for(int i=1;i<=N-1;i++)M[i]=0;
    for(int i=0;i<N;i++)
     M.at(a[i])++;
                for(int i=a[0];i<=a[N-1];i++){
                if(i==a[0]){if(M.at(i)!=1){x=false;break;}}
                            else{if(M.at(i)<=1){x=false;break;}}
                             
                }
    if(x)cout<<"Possible"<<endl;
                              else
                                cout<<"Impossible"<<endl;
  }else{
                    map<int,int>M;
     for(int i=1;i<=N-1;i++)M[i]=0;
    for(int i=0;i<N;i++)
     M.at(a[i])++;
                for(int i=a[0];i<=a[N-1];i++){
                if(i==a[0]){if(M.at(i)!=2){x=false;break;}}
                            else{if(M.at(i)<=1){x=false;break;}}
                             
                }
                  if(x)cout<<"Possible"<<endl;
                              else
                                cout<<"Impossible"<<endl;
  
  }
  return 0;
}