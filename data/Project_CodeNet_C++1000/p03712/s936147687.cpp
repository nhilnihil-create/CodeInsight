#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int h, w;
    cin >> h >> w;
    string a;
    
    for(int i = 0; i < w+1; ++i){
        cout << "#";
    }
    cout << "#" << endl;
    
    vector<string> x(h);
    for(int i = 0; i < h; ++i){
        cin >> x.at(i);
    }
    
    for(int i = 0; i < h; ++i){
        cout << "#" << x.at(i) << "#" << endl;
    }
    
    for(int i = 0; i < w+1; ++i){
        cout << "#";
    }
    cout << "#" << endl;
}
