#include <bits/stdc++.h>
#include <string>
using namespace std;

string s;
int a,b;


int main(){
    cin>>s;
    a=s.find("A");
    b=s.rfind("Z");
    cout<<b-a+1<<endl;
}