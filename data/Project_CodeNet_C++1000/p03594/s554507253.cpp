#include <fstream>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <climits>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int BUFFSIZE = 1 << 17;

char buffer[BUFFSIZE];
int pointer = BUFFSIZE;

char Advance() {
    if (pointer == BUFFSIZE) {
        fread(buffer, 1, BUFFSIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

char color[2][2] = {{'B', 'G'},
                    {'R', 'Y'}};

char Color(int i, int j, int d) {
    return color[(i / d) % 2][(j / d) % 2];
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int i0 = j + i, j0 = j - i + n;
            char ch = Color(i0, j0, d);
            printf("%c", ch);
            if (j == m - 1)
                printf("\n");
        }
    return 0;
}
