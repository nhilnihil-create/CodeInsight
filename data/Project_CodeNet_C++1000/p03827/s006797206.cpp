#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin >> n;
string s;
cin >>s;
int mx=0;
int value =0;
for(int i=0;i<n;i++){
if(s[i]=='I'){
value++;
}else{
value--;
}
mx=max(mx,value);
}
cout<<mx<<endl;
}