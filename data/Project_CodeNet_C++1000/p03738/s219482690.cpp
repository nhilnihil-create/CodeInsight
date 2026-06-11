#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace boost::multiprecision;
using namespace std;
int main(){
    cpp_int a,b;
    cin>>a;
    cin>>b;
    if(a>b){
        cout<<"GREATER"<<endl;
    }
    else if(a<b){
        cout<<"LESS"<<endl;
    }
    else{
        cout<<"EQUAL"<<endl;
    }
    return 0;
}
