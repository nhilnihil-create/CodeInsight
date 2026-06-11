#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main() {
    
    int w, h, n;
    int i, j, k;
    int x, y, a;
    bool square[100][100];
    int count = 0;

    for(i=0; i<100; i++){
        for(j=0; j<100; j++){
            square[i][j] = false;
        }
    }

    cin >> w >> h >> n;

    for(i=0; i<h; i++){
        for(j=0; j<w; j++){
            square[i][j] = true;
        }
    }

    for(k=0; k<n; k++){
        cin >> x >> y >> a;
        
        switch(a){
            case 1:
                for(i=0; i<h; i++){
                    for(j=0; j<x; j++){
                        square[i][j] = false;
                    }
                }
                break;
            case 2:
                for(i=0; i<h; i++){
                    for(j=x; j<w; j++){
                        square[i][j] = false;
                    }
                }
                break;
            case 3:
                for(i=0; i<y; i++){
                    for(j=0; j<w; j++){
                        square[i][j] = false;
                    }
                }
                break;
            case 4:
                for(i=y; i<h; i++){
                    for(j=0; j<w; j++){
                        square[i][j] = false;
                    }
                }
                break;
        }
    }

    for(i=0; i<h; i++){
        for(j=0; j<w; j++){
            if(square[i][j]){
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}

