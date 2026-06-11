#include <iostream>

using namespace std;

#define MAX_L 100
int square[MAX_L][MAX_L];
int r, c;

int counts[MAX_L * MAX_L];
int n;
void fillColor();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c >> n;
    int i;
    for(i = 0; i < n; ++i){
        cin >> counts[i];
    }
    fillColor();
    int j;
    for(i = 0; i < r; ++i){
        for(j = 0; j < c; ++j){
            cout << square[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

void fillColor(){
    int x, y;
    int i = 0;
    for(x = 0; x < r; ++x){
        if((x & 1) == 0){
            for(y = 0; y < c; ++y){
                square[x][y] = i + 1;
                if(--counts[i] <= 0){
                    ++i;
                }
            }
        }
        else{
            for(y = c - 1; y >= 0; --y){
                square[x][y] = i + 1;
                if(--counts[i] <= 0){
                    ++i;
                }
            }
        }
    }
}
