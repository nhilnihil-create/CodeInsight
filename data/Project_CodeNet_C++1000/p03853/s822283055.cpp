#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    
    vector<string> image(h);
    for (int i = 0; i<image.size(); i++){
        cin >> image.at(i);
        for (int j = 0; j<2; j++){
            cout << image.at(i) << endl;;
        }
    }    
}