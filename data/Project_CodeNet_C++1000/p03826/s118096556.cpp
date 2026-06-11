#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, area1, area2;
    cin >> a >> b >> c >> d;
    area1 = a * b;
    area2 = c * d;
    if(area1 > area2)
        cout << area1;
    else if(area1 < area2)
        cout << area2;
    else
    cout << area1;


    return 0;
}
