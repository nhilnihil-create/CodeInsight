#include <iostream>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    char a[102][102];
    int b[26] {0};
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++){
        cin >> a[i][j];
        b[a[i][j] - 'a']++;
    }
    if(h % 2 == 0 && w % 2 == 0){
        for(int i = 0; i < 26; i++){
            if(b[i] % 4){
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }
    if(h % 2 == 0 && w % 2 != 0){
        int r = 0;
        for(int i = 0; i < 26; i++){
            if(b[i] % 2){
                cout << "No" << endl;
                return 0;
            }
            if(b[i] % 4) r++;
        }
        if(r <= h / 2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    if(h % 2 != 0 && w % 2 == 0){
        int r = 0;
        for(int i = 0; i < 26; i++){
            if(b[i] % 2){
                cout << "No" << endl;
                return 0;
            }
            if(b[i] % 4) r++;
        }
        if(r <= w / 2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    if(h % 2 != 0 && w % 2 != 0){
        int r = 0, s = 0;
        for(int i = 0; i < 26; i++){
            if(b[i] % 2) s++;
            else if(b[i] % 4) r++;
        }
        if(s <= 1 && r <= h / 2 + w / 2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}