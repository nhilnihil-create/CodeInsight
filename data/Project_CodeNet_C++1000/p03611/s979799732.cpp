#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    int count[100000] = {};
 
    cin >> n;
    int m1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m1);
        count[m1]++;
        if (m1 - 1 >= 0)
            count[m1 - 1]++;
        if (m1 + 1 < 100000)
            count[m1 + 1]++;
    }
 
    int max = 0;
    for (int i = 0; i < 100000; i++)
    {
        if (count[i] > max)
            max = count[i];
    }
 
    cout << max << endl;
 
    return 0;
}