#include <bits/stdc++.h>
using namespace std;

int main(){
int N;
  cin >> N;
int d[N];
for(int i=0;i<N;i++) cin >> d[i]; 
  
int count=1;
int needh=0;  
for(int i=0;i<N-1;i++){

if(d[i]>d[i+1] && needh==0){
  needh=-1;
  continue;
 }
if(d[i]<d[i+1] && needh==0){
  needh=1;
  continue;
}
if(needh==1 && d[i]>d[i+1]){
count++;
needh=0;  
}  

if(d[i]<d[i+1] && needh==-1){
count++;
needh=0;  
}        
} 

cout << count << endl;
}