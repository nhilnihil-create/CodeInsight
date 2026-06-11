#include<bits/stdc++.h>
using namespace std;
int st(string s){
    int a=0;
    int z=s.size()-1;
    while(s.at(a)!='A'){
        a++;
    }
    while(s.at(z)!='Z'){
        z--;
    }
    


    return z-a+1;
}
int main(){
    string s;
    cin>>s;
    cout<<st(s)<<endl;
    
}