#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>


using namespace std;
int main() {
    int H,W;
    cin >> H >> W;
    int count[30];
    for(int i = 0; i < 30; i++){
        count[i] = 0;
    }
    for(int i = 0; i < H * W; i++){
        char tmp;
        cin >> tmp;
        count[tmp - 'a']++;
    }
    int odd = 0;
    if(H % 2 == 1 && W % 2 == 1){
        odd++;
    }
    int even = 0;
    if(H % 2 == 1){
        even += W / 2;
    }
    if(W % 2 == 1){
        even += H / 2;
    }
    int mod4 = 0;
    mod4 += H / 2 * W / 2;
    for(int i = 0; i < 30; i++){
        switch (count[i] % 4){
            case 0:
                break;
            case 1:
                odd--;
                break;
            case 2:
                even--;
                break;
            case 3:
                odd--;
                even--;
                break;
        }
    }
    if(odd >= 0 && even >= 0 && mod4 >= 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}