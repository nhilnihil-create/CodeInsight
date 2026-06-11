#include <iostream> 
#include <stdlib.h> 
#include <string.h> 
#include <string> 
#include <sstream>
#include <cstring> 
#include<cmath>
using namespace std;
int main()
{
    int  x , y;
    cin >> x >> y;
    
    for (int i = 0; i < y + 2; i++) {
        cout << "#";
    }
    cout << "\n";
    for (int i = 0; i < x ; i++) {
        string z;
        cin >> z;
        cout << "#" << z << "#\n";
    }
    for (int i = 0; i < y + 2; i++) {
        cout << "#";
    }
	

    return 0;
}