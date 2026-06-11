#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    vector<string> b(H + 2);
    for(int i = 0; i < H; i++){
        cin >> a.at(i);
    }
    for(int i = 0; i < H + 2; i++){
        for(int j = 0; j < W + 2; j++){
            (b.at(i)).push_back('#');
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            (b.at(i + 1)).at(j + 1) = (a.at(i)).at(j);
        }
    }
    for(int i = 0; i < H + 2; i++){
        cout << b.at(i) << endl;
    }
    /*for(int i = 0; i < H + 2; i++){
        if(i == 0 || i == H + 1){
            for(int j = 0; j < W + 2; j++){
                cout << "#";
            }
        }else{
            for(int j = 0; j < W + 2; j++){
                if(j == 0 || j == W + 1){
                    cout << "#";
                }else{
                    cout << (a.at(i - 1)).at(j - 1);
                }
            }
        }
        cout << endl;
    }*/
}

/*
terminate called after throwing an instance of 'std::out_of_range'
  what():  basic_string::at: __n (which is 0) >= this->size() (which is 0)
*/