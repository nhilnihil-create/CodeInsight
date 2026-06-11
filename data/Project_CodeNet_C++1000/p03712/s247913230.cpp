#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> pic(h);
    for(int i = 0; i < h; i++){
        string a;
        cin >> a;
        pic[i] = "#" + a + "#";
    }
    cout << string(w+2, '#') << endl;
    for(string s : pic) cout << s << endl;
    cout << string(w+2, '#') << endl;
}