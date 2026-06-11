#include <iostream>
using namespace std;

int main(){
    int x,y,z;
    cin >> x >> y >> z;
    if(x==y && y==z){
        cout << 1 << endl;
        return 0;
    }else if(x==y && y!=z){
        cout << 2 << endl;
        return 0;
    }else if(z==y && y!=x){
        cout << 2 << endl;
        return 0;
    }else if(x==z && y!=z){
        cout << 2 << endl;
        return 0;
    }else{
        cout << 3 << endl;
        return 0;
    }
}