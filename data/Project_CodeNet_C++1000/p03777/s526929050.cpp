#include<iostream>
#include<string>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    if (a[0] == 'H'){
        if (b[0] == 'H'){
            cout << 'H' << endl; 
        }else{
            cout << 'D' << endl; 
        }
    }else{
        if (b[0] == 'H'){
            cout << 'D' << endl; 
        }else{
            cout << 'H' << endl; 
        }        
    }
    
}