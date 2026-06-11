#include <iostream>
#include <string>
using namespace std;

int main() {
    string op;
    int i=1;
    getline(cin,op);
    while(op.at(i)!=' '){
     i++;
    }
    cout << "A" << op.at(i+1) << "C" << endl;

}