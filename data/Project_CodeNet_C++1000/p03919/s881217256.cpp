#include <iostream>
#include <string>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++){
            string s;
            cin >> s;
            if(s == "snuke"){
                string t = "";
                t.push_back('A' + j);
                t += to_string(i+1);
                cout << t << endl;
            }
        }

    return 0;
}