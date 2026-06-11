#include<bits/stdc++.h>
using namespace std;
bool arr[12];
bool check(int n){
 while(n!=0){
   int rem=n%10;
   if(arr[rem]){
    return false ;
   }
   n=n/10;
 }
 return true ;
}
int main(){
 int N , k;
 cin >> N >> k ;
 for(int i=1;i<=k;i++){
   int x;
   cin >> x;
   arr[x]=true ;
 }
 for(int i=N;i<=1000000000;i++){
   if(check(i)){
     cout << i <<endl;
     return 0;  
   }
 } 
 return 0;	
}
