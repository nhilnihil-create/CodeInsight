/**
  *  Worg
  */
#include <cstdio>

//FILE *fin = freopen("main.in", "r", stdin); FILE *fout = freopen("main.out", "w", stdout);

const int kMaxN = 500 + 5;

int N, M, D;

char answer[kMaxN][kMaxN];

void GiveColor(int x, int y, int zoneX, int zoneY) {
    if(zoneX % 2 == 0) {
        if(zoneY % 2 == 0) {
            answer[x][y] = 'R';
        } else {
            answer[x][y] = 'Y';
        }
    } else {
        if(zoneY % 2 == 0) {
            answer[x][y] = 'G';
        } else {
            answer[x][y] = 'B';
        }
    }
}

void BuildAnswer() {
    const int minX = 0, minY = -N+1;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int x = i + j, y = j - i;
            int zoneX = (x - minX) / D, zoneY = (y - minY) / D;

            //printf("%d %d %d %d\n", x, y, zoneX, zoneY);
            GiveColor(i, j, zoneX, zoneY);
        }
    }
}

void WriteOutput() {
    for(int i = 0; i < N; i++) {
        printf("%s\n", answer[i]);
    }
}

int main() {
    scanf("%d%d%d", &N, &M, &D);

    BuildAnswer();

    WriteOutput();
    return 0;
}
