#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int>a(N);
  for(int i=0;i<N;i++)
    cin>>a.at(i);
  sort(a.begin(),a.end());
  if(a.at(0)==a.at(N-1)){
  if(a.at(0)==N-1 || 2*a.at(0)<=N)
    cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }else if(a.at(N-1)-a.at(0)==1){
     int A=a.at(0); int B=a.at(N-1);
    map<int,int>M; M[A]=0; M[B]=0;
    for(int i=0;i<N;i++)
      if(a.at(i)==A)
        M.at(A)++;
    else
      M.at(B)++;
    int k=M.at(A);
    if(B-k<=0)
      cout<<"No"<<endl;
    else{
     if(2*B-k<=N)
       cout<<"Yes"<<endl;
      else
        cout<<"No"<<endl;
    }
  }else
    cout<<"No"<<endl;
   return 0;
}
