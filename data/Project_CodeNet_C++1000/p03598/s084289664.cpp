#include<bits/stdc++.h>
using namespace std;
int main(){
int n,k;
cin >>n>>k;
vector<int> x(n);
for(int i=0;i<n;i++){
cin >> x.at(i);
}
int output =0;
for(int i=0;i<n;i++){
int a=x.at(i);
int b=abs(x.at(i)-k);
if(a>b){
output += 2 * b;
}else{
output += 2 * a;
}

}
cout << output <<endl;
  
  
}