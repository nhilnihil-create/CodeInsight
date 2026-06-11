#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    string s;
    cin >> s;
    string devide[] = {"dream", "dreamer", "erase", "eraser"};

    /* code */
    queue<int> bfs;
    bfs.push(0);

    while (!bfs.empty())
    {
        /* code */
        int a = bfs.front();
        bfs.pop();

        if (a == s.size())
        {
            cout << "YES" << endl;
            return 0;
        }

        for (string d : devide)
        {
            if (s.substr(a, d.size()) == d)
            {
                bfs.push(a + d.size());
            }
        }
    }

    cout << "NO" << endl;
}