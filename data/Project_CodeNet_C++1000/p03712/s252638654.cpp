#include <iostream>
#include <string>
using namespace std;

void sharp(int w){
    for (int i = 0; i < w+2; i++){
        cout << "#";
    }
}

int main(void){
    int h, w;
    string h1 = "#", w1 = "#";
    cin >> h >> w; // i = h, j = w 
    string S[100];
    
    for(int i = 0; i < 100; i++){
        cin >> S[i];
    }
    
    sharp(w);
    cout << endl;
    
    for(int i = 0; i < h; i++){
        cout << "#" << S[i] << "#" << endl;
    }
    
    sharp(w);
}