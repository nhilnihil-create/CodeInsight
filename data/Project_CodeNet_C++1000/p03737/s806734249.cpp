#include <iostream>
#include <string>
using namespace std;

string kata1, kata2, kata3, acronym;

int main () {
    cin>>kata1>>kata2>>kata3;
    kata1 [0]-=32;
    kata2 [0]-=32;
    kata3 [0]-=32;
    cout<<kata1[0]<<kata2[0]<<kata3[0];
}