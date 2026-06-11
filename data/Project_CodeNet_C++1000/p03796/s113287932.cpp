#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin >> n;
long long  output =1; 
for(int i=1;i<=n;i++){
output *= i;
output = output %(1000000000+7)  ; 
}
cout<<output<<endl;
}