#include<bits/stdc++.h>

using namespace std;

int main(){
   string a, b;
   cin>>a>>b;



   if(a.length()>b.length()) cout<<"GREATER";
   else if(a.length()<b.length()) cout<<"LESS";
   else{
        int c1, c2;
        bool bb=true;
        for(int i=0; a[i]; i++){
            if(a[i]==b[i]){}
            else{
                bb=false;
                c1= a[i]-'0';
                c2= b[i]-'0';
                break;
            }
        }
        if(bb) cout<<"EQUAL";
        else if(c1>c2) cout<<"GREATER";
        else if(c1<c2) cout<<"LESS";
   }
}
