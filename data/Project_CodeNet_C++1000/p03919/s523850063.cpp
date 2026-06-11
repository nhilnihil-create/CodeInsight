#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    string str;
    int h, w;

    cin >> h >> w;

    for (int i = 1; i <= h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> str;
            if (str == "snuke") {
                printf("%c%d\n", 'A' + j, i);
            }
        }
    }

    return 0;
}
