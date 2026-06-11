#include<iostream>
#include<math.h>
using namespace std;

#define ll long long
int main(){

string s;
cin>>s;

int start=-1, end=-1;
bool flag=false;
for(int i=1;i<s.length();i++){
    
    if(flag)
    break;
    
    if(s[i-1]==s[i]){
        start=i-1+1;
        end=i+1;
        flag=true;
    }
    if(i-2 >=0 && s[i-2]==s[i]){
         start=i-2+1;
        end=i+1;
        flag=true;
    }
    
}

cout<<start<<" "<<end;
  
}