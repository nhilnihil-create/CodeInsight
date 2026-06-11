#include <bits/stdc++.h>
using namespace std;

int main(){
int n,b;
  cin >> n >> b;
string a[n];
for(int i=0;i<n;i++){
cin >> a[i];
}
   string f=a[0];
 for(int i=0;i<n;i++){
 for(int j=i+1;j<n;j++){
  if(a[j]<a[i]){
   f=a[j];
   a[j]=a[i];
   a[i]=f;
  }
 }
 } 
 for(int i=0;i<n;i++){
  cout << a[i];
 } 

}