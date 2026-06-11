#include <iostream>

using namespace std;

bool find_cand(char c0, char c1, int N, const char *ans, char *cand);

int main()
{
    int N;
    string s;

    cin >> N;
    cin >> s;

    const char *ans = s.c_str();

    char cand[100'001];

    if (find_cand('S', 'S', N, ans, cand) ||
        find_cand('S', 'W', N, ans, cand) ||
        find_cand('W', 'S', N, ans, cand) ||
        find_cand('W', 'W', N, ans, cand))
    {
        cout << cand << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}

bool find_cand(char c0, char c1, int N, const char *ans, char *cand)
{
    cand[N] = '\0';

    cand[0] = c0;
    cand[1] = c1;

    for (int i = 0; i < N; i++)
    {
        int curr = i + 2;
        bool same = ans[(curr - 1) % N] == 'o';
        bool honest = cand[(curr - 1) % N] == 'S';
        bool sheep = cand[(curr - 2) % N] == 'S';

        cand[curr % N] = !(honest ^ same) ? sheep ? 'S' : 'W'
                                          : sheep ? 'W' : 'S';
    }

    return cand[0] == c0 && cand[1] == c1;
}