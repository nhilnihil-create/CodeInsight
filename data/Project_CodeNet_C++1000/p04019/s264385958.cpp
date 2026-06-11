#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string S;
    cin >> S;
    int dir[4] = {};
    for (char c : S)
    {
        if (c == 'N') dir[0]++;
        if (c == 'S') dir[1]++;
        if (c == 'W') dir[2]++;
        if (c == 'E') dir[3]++;
    }

    bool okNS = false;
    bool okWE = false;
    if ((dir[0] > 0 && dir[1] > 0) || (dir[0] == 0 && dir[1] == 0))
    {
        okNS = true;
    }
    if ((dir[2] > 0 && dir[3] > 0) || (dir[2] == 0 && dir[3] == 0))
    {
        okWE = true;
    }

    if (okNS & okWE)
    {
        cout << "Yes" << endl;
    }else
    {
        cout << "No" << endl;
    }
    
    return 0;
}