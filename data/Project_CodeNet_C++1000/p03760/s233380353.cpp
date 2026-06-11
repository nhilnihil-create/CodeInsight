#include <iostream>
using namespace std;

int main() {
    string stra,strb;
    int x,y,z,k=0,q=0;
    cin >> stra;
    cin >> strb;
    x= stra.length();
    y= strb.length();
    z=x+y;
    for(int i=0;i<z;i++){
        if(i%2!=0){
            cout << strb[k];
            k++;
        }else if(i%2==0){
            cout << stra[q];
            q++;
        }
    }
    cout << endl;
}