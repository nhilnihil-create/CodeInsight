#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D,E,F;
  cin>>A>>B>>C>>D>>E>>F;
  vector<int> w(30);
  vector<int> s(30*E);
  w.at(0)=1,s.at(0)=1;
  for(int i=A;i<30;i++){
    w.at(i)+=w.at(i-A);
  }
  for(int i=B;i<30;i++){
    w.at(i)+=w.at(i-B);
  }
  for(int i=C;i<30*E;i++){
    s.at(i)+=s.at(i-C);
  }
  for(int i=D;i<30*E;i++){
    s.at(i)+=s.at(i-D);
  }
  vector<int> W;
  vector<int> S;
  for(int i=0;i<30;i++){
    if(w.at(i)!=0){
      W.push_back(i);
    }
  }
  for(int i=0;i<30*E;i++){
    if(s.at(i)!=0){
      S.push_back(i);
    }
  }
  int N=W.size();
  int M=S.size();
  int X=W.at(1),Y=0,a=0;
  for(int i=1;i<N;i++){
    if(W.at(i)*E>S.at(M-1)){
      break;
    }
    else{
      int b=lower_bound(S.begin(),S.end(),W.at(i)*E+1)-S.begin();
      for(int j=a;j<b;j++){
        if(W.at(i)*Y<X*S.at(j)&&W.at(i)*100+S.at(j)<=F){
          X=W.at(i),Y=S.at(j);
        }
      }
    }
  }
  cout<<100*X+Y<<" "<<Y<<endl;
        
      
}


