#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;

int main(){
 int A,B,C;
 cin>>A>>B>>C;
 int count=0;
while(A%2==0&&B%2==0&&C%2==0){
  if(A==B&&B==C){cout<<-1<<endl;return 0;}
  else{int AA=(B+C)/2;int BB=(A+C)/2;int CC=(A+B)/2;
       A=AA;B=BB;C=CC;
  count++;}
}
cout<<count<<endl;
  return 0;
}