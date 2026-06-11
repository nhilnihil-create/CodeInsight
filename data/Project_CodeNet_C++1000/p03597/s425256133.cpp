#include <iostream>
using namespace std;

int main (){
int len;
int wh;
int area;
int output;
cin >> len;
cin >> wh;

area = len*len;
output = area - wh;

cout << output;

return 0;
}