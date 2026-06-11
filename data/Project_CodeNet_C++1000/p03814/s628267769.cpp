#include <iostream>
#include <string>
using namespace std;

int pnjg, pnjgout, indexa=2000000, indexz=-1;
string input, A="A", Z="Z";

int main (){
    cin>>input;
    pnjg = input.length ();
    for (int i=0; i<=pnjg; i++){
        if (input [i]==A[0] && i<indexa){
            indexa=i;
        }
        if (input [i]==Z[0] && i>indexz){
            indexz=i;
        }
    }
    cout<<indexz-indexa+1<<endl;
}