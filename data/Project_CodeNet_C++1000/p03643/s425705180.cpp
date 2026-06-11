#include<iostream>
#include<sstream>
using namespace std;

int main(){
int N;
cin>>N;
stringstream ss;
string k;
ss<<N;
ss>>k;
k="ABC"+k;
cout<<k;
}


