#include <string>
#include <iostream>
using namespace std;
string cf = "CODEFESTIVAL2016";
int main()
{
    string a;
    int cnt = 0;
    cin >> a;
    for(int i = 0;i < 16;i++)
    {
        if(cf[i] != a[i])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}