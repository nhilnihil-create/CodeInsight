#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    cin >> a;
    int l=a.size(),i;
    for (i=0;i<(l+1)/2;i++)
        if (a[i]=='p'&&a[l-1-i]!='q'||a[i]=='q'&&a[l-1-i]!='p'||a[i]=='b'&&a[l-1-i]!='d'||a[i]=='d'&&a[l-1-i]!='b')
        {
            cout << "No";
            return 0;
        }
    cout << "Yes";
    return 0;
}