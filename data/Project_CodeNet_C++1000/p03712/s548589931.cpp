#include<iostream>
#include<string>

using namespace std;

int main(){
    int h, w;
    string s, n;

    cin >> h >> w;

    for(int i = 0; i < w + 2; i++) s.push_back('#');
    cout << s << endl;

    for(int i = 0; i < h; i++){
        cin >> n;
        cout << "#" << n << "#" << endl;
    }
    cout << s << endl;
}