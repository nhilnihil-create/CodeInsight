#include<iostream>
using namespace std;

int main(void){
    int x,a,b = 0;
    cin >> x >> a >> b;
    int absa = abs(x-a);
    int absb = abs(x-b);
    if(absa <= absb){
        cout << "A";
    }else
    {
        cout << "B";
    }
    
}