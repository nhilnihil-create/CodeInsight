#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    if(a==b){
        cout<<"EQUAL"<<endl;
    }
    else if(a.size()>b.size()||(a.size()==b.size()&&a>b)){
        cout<<"GREATER"<<endl;
    }
    else{
        cout<<"LESS"<<endl;
    }
    return 0;
}
