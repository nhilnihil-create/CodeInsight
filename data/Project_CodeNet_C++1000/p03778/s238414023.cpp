#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int w,a,b;
    cin>>w>>a>>b;
    if(a<b){
        if(0<(b-a-w)){cout<<(b-a-w);}
        else{cout<<0;}
    }
    else{
       if(0<(a-b-w)){cout<<(a-b-w);}
        else{cout<<0;} 
    }
    return 0;
}