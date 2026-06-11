#include<iostream>
#include<vector>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> pix(h);
    for(int i = 0;i<h;i++){
        cin >> pix.at(i);
    }
    //cout << pix.at(0).size() << endl;
    for(int i=0;i<pix.at(0).size()+2;i++){
        cout << '#';
    }
    cout << endl;
    for(int i=0;i<h;i++){
        cout << '#' << pix.at(i) << '#' << endl;
    }
    for(int i=0;i<pix.at(0).size()+2;i++){
        cout << '#';
    }
    return 0;
}