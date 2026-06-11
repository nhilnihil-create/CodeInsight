#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int input1, input2;
    string op;
    cin>> input1;
    cin>> op;
    cin>> input2;

    if(op=="+"){
        cout<<input1+input2<< endl;
    }
    else{
        cout<<input1-input2<< endl;
    }

    return 0;
}

