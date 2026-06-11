#include<bits/stdc++.h>
using namespace std;
int amount , dig ;
bool arr[12];
bool isokay(int amount){
  int rem ;
  while(amount!=0){
    rem=amount%10 ;
    if(arr[rem]==true){
      return false ;
    }
    amount = amount /10;
  }
  return true ;
}
int main(){
 cin >> amount >> dig ;
 for(int i=1;i<=dig;i++){
    int x;
    cin >> x ;
    arr[x]=true ;
 }
 for(int i=amount;;i++){
    if(isokay(i)){
      cout << i <<endl;
      return 0;
    }
 }
 return 0;
}
