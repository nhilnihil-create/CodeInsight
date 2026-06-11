#include<bits/stdc++.h>
using namespace std;
int main(){
  long long X,A,B;
  cin>>X>>A>>B;
  long long C=B-A;
  if(C<=0){
    cout<<"delicious"<<endl;
  }
  else if(C>0&&C<=X){
    cout<<"safe"<<endl;
  }
  else{
    cout<<"dangerous"<<endl;
  }
}
