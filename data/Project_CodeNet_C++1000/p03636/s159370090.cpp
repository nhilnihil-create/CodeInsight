#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
    char a_b,a_e;
    int b;
    cin>>a;
    b=a.size();
    a_b=a.at(0);
    a_e=a.at(b-1);
    b-=2;
    cout<<a_b<<b<<a_e<<endl;
}