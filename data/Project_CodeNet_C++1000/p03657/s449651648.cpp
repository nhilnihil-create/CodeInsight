#include<iostream>

using namespace std;

int main(void){
    int a,b,s=0;
    cin >> a >> b;
    s = a + b;
    if(a % 3 == 0){
        cout << "Possible";
    }else if (b % 3 == 0)
    {
        cout << "Possible";
    }else if (s % 3 == 0)
    {
        cout << "Possible";
    }else{
        cout << "Impossible";
    }
    
    
}