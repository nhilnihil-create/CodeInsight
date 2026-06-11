#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string a;
    cin >> a;
    int b = a.size() - 2;
    cout << a[0] << b << a[b + 1];
    
    return 0;
}