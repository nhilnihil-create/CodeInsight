#include<bits/stdc++.h>
using namespace std;
int main(){
int n,a,b;
cin >>n>>a>>b;
string s;
cin >>s;
int genzai=0;
int genzai_f=0;
for(int i=0;i<n;i++){
string output;
if(s[i]=='a'){
if(genzai<a+b){
output = "Yes";
genzai++;
}
else{
output ="No";
}
}else if(s[i]=='b'){
if(genzai<a+b&&genzai_f<b){
output = "Yes";
genzai++;
genzai_f++;
}else{
output ="No";
}
}else{
  
output ="No";
}

cout << output <<endl;

}
}