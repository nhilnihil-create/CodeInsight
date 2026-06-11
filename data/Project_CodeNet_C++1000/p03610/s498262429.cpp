#include <iostream>
#include <string>
using namespace std;

int pnjg, j;
string input, output;

int main (){
    cin>>input;
    pnjg=input.length();
    if (pnjg%2==0){
        pnjg--;
    }
    for (int i=0; i<=pnjg; i+=2){
        output+=input[i];
        j++;
    }
    cout<<output<<endl;
}