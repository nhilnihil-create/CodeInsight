#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int h, w, i, j;
    cin >> h >> w;
    //int arr[h][w];
    vector<string> arr;
    
    for(i=0; i<h; i++){
        string s;
        cin >> s;
        arr.push_back(s);
    }
    for(j=0; j<=w; j++){
        cout << '#';
    }
    cout << '#' << endl;
    for(i=0; i<h; i++){
        cout << '#';
        cout << arr[i];
        cout << '#' << endl;
    }
    for(j=0; j<=w; j++) cout << '#';
    cout << '#' << endl;
    return 0;
}