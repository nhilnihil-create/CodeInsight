#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b;
  cin >> a >> b;
  
  if(a<=0&&0<=b)
    cout << "Zero"<<endl;
  if(a<=b&&b<0){
    if((b-a+1)%2==1)
      cout <<"Negative"<< endl;
    if((b-a+1)%2==0)
      cout << "Positive"<<endl;
  }
  if(0<a&&a<=b)
    cout<<"Positive"<<endl;
}