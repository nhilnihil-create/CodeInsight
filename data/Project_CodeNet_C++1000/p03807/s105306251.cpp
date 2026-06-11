#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int a[110000];
    int num = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        if(a[i]%2 != 0) num++;
    }
    if (num%2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}