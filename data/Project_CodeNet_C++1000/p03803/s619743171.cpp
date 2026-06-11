#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin >> a >> b;
  int s[13]={13,1,2,3,4,5,6,7,8,9,10,11,12};
  if(a==b){
    cout << "Draw";
  }else if(s[a-1]>s[b-1]){
    cout << "Alice";
  }else{
    cout << "Bob";
  }
}
