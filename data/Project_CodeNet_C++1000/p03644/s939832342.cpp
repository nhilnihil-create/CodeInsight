#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin >>n;
int num=0;
int output=1;
for(int i=1;i<=n;i++){
int count=0;
int kazu = i;
while(kazu%2==0){
count++;
kazu = kazu/2;
}

if(count>num){
num = count;
output= i;
}

}
  
cout << output <<endl; 
}