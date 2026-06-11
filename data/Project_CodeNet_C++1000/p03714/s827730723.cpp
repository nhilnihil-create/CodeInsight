#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int64_t>A(3*N);
  for(int i=0;i<3*N;i++)
    cin>>A.at(i);
  int64_t a=0;priority_queue<int64_t, vector<int64_t>, greater<int64_t> >que1;
  for(int i=0;i<N;i++){a+=A.at(i); que1.push(A.at(i));}
  vector<int64_t>B(3*N);vector<int64_t>C(3*N);
  B.at(N-1)=a;
  for(int i=N;i<2*N;i++){
  a+=A.at(i);que1.push(A.at(i));
    int64_t b=que1.top(); que1.pop();
    a-=b; B.at(i)=a;
  }int64_t c=0;priority_queue<int64_t, vector<int64_t>, greater<int64_t> > que2;
  for(int i=3*N-1;2*N<=i;i--){c-=A.at(i);que2.push(-A.at(i));}
  C.at(2*N)=c;
  for(int i=2*N-1;N<=i;i--){
  c-=A.at(i); que2.push(-A.at(i));
    int64_t b=que2.top();que2.pop();
    c-=b;C.at(i)=c;
  }int64_t ans=-1000000000000000;
  for(int i=N-1;i<2*N;i++)
    if(ans<B.at(i)+C.at(i+1))
      ans=B.at(i)+C.at(i+1);
  cout<<ans<<endl;
  return 0;
}