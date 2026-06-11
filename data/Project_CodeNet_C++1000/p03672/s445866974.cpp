#include <iostream>
using namespace std;

int main() {
    string stra;
    int x;
    cin >> stra;
    x= stra.length();
    x=x-1;
    for(int i=x-1;i>=0;i--){
        if(i%2==1 && stra.substr(0,i/2+1)==stra.substr(i/2+1,i/2+1)){
            cout << i+1 << endl;
            break;
        }
    }
}