#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int main() {
    long long a, b; cin>>a>>b;
    long long counter=0;
    int counter1=0;
    int counter2=0;
    long long answer=0;
    if(b<0){
    counter=abs(b-a)+1;
    if(counter%2==0){
    cout<<"Positive"<<endl;}
    else
    cout<<"Negative"<<endl;}
    else if(a>0)
    cout<<"Positive"<<endl;
    else 
    cout<<"Zero"<<endl;}
    
