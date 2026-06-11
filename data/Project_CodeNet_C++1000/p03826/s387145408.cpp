#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, area1, area2;
    cin >> a >> b >> c >> d;
    area1= a*b;
    area2= c*d;
    if (1 <= a && a <= 10000 && 1 <= b && b <= 10000 && 1 <= c && c <= 10000 && 1 <= d && d <= 10000 )
    {
       if (area1 > area2)
            cout << area1;
       else if (area1 == area2)
            cout << area1;
       else if (area1 < area2)
            cout << area2;
    }
    return 0;


}