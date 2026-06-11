#include <iostream>
using namespace std;

int main(){
    int n;
    int nn=0;
    cin>>n;
    while(n>0){
        nn += n;
        n--;
    }
    cout<<nn;
}
