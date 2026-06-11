#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string S;
    cin>>S;
    int c,d;
    for(int i=0;i<S.size();i++){
       if(S.at(i)=='A'){
            c=i+1;
           break;
       }
    }
    reverse(S.begin(),S.end());
    for(int i=0;i<S.size();i++){
        if(S.at(i)=='Z'){
             d=i+1;
            break;
        }
    }
    cout <<S.size()-c-d+2<<endl;  
   
}