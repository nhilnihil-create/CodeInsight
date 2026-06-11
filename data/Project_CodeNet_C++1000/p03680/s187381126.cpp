#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
  cin >> n;
map<int,int> a;
for(int i=1;i<=n;i++) cin >> a[i] ;
bool flag=false;  
int num=0;
int i=1;  
int j=1;  
while(a[i]>0){
  num++;
  j=i;
if(a[j]==2){
            flag=true;
            break;
            }
else {
  j=a[i];
  a[i]=-1;
  i=j;
     }
}  
  if(flag) cout << num << endl;
  else cout << -1 << endl;
}  


