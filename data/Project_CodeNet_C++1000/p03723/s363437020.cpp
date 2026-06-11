#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin >>a>>b>>c;
  int count =0;
  while(a%2==0 && b%2==0 && c%2==0){
    count++;
    int tmpa=a;
    int tmpb=b;
    int tmpc=c;
    a=tmpb/2+tmpc/2;
    b=tmpa/2+tmpc/2;
    c=tmpa/2+tmpb/2;
    if(a==tmpa&&b==tmpb&&c==tmpc){
      cout<<-1<<endl;
      return 0;
    }
  }
  cout<<count<<endl;
  return 0;
}