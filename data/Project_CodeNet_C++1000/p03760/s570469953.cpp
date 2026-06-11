#include <iostream>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    for(int i = 0; i<min(a.size(), b.size()); i++)
        cout << a[i] << b[i];
    if(a.size()>b.size())cout<<a[a.size()-1];
    else if(a.size()<b.size())cout << b[a.size()-1];
}
