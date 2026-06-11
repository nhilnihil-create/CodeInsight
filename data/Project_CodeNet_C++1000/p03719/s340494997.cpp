#include <iostream>
using namespace std;

int main ()
{
    int r;
    int m;
    int a;
    cin >> r>>m>>a;
    if (a<m&&a>r){
        cout << "Yes";
    }
else if (a==r&&a==m){
    cout << "Yes";
}
else cout << "No";

    return 0;
}
