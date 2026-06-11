#include<iostream>
using namespace std;
int main()
{
    int x, y;
    int q1 = 0,q2 = 0;
    cin >> x >> y;
    if(x == 11 || x == 9 || x == 6 || x == 4)
        q1 = 2;
    else if(x == 2)
        q1 = 3;
    else q1 = 1;
    if(y == 11 || y == 9 || y == 6 || y == 4)
        q2 = 2;
    else if(y == 2)
        q2 = 3;
    else q2 = 1;
    if(q1 == q2)
        cout << "Yes";
    else
        cout << "No";

     return 0;
}
