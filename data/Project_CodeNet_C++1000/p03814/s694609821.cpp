#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int A,Z,a=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(a==0){
            if(s.at(i)=='A'){
            A=i;
            a=1;
            }
        }else if(a<=i+1&&s.at(i)=='Z'){
            Z=i;
            a=i;
        }
    }
    cout<<Z-A+1<<"\n";
}