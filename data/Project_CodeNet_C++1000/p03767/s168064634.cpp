#include <bits/stdc++.h>
using namespace std; 

int main(){
int n;
  cin >> n;
int N=3*n;  
  int a[N];
for(int i=0;i<N;i++){
 cin >> a[i];
}
sort(a,a+N);
long long sum=0;
  for(int i=n;i<3*n;i+=2){
   sum+=a[i];
 }
  cout << sum << endl;
  
}
