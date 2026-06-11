#include <iostream>
#include <string>
using namespace std;

int n, bnykkarakter;
string input;

int main (){
    cin>>input;
    n=input.length();
    bnykkarakter=n-2;
    cout<<input[0]<<bnykkarakter<<input[n-1];
}