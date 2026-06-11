#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    
    int h, w;
    cin >> h >> w;
    
    string S[100];
    for(int i = 0; i < h; i ++){
        cin >> S[i];
    }
    for(int i = 0; i < w + 2; i ++){
        cout << "#";
    } cout << endl;
    
    for(int i = 0; i < h; i ++){
        cout << "#" << S[i] << "#" << endl;
    }
    
    for(int i = 0; i < w + 2; i ++){
        cout << "#";
    } cout << endl;
}