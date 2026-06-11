#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int x;
    cin >> x;
    int temp=sqrt(2*x);
    if((temp*(temp+1)/2)<x)temp++;
    cout << temp << endl; 
    return 0;
}