#include<bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<string>> s(H,vector<string>(W));
    int i,j;
    int h=0;
    int g=0;
    char t;

    for(i=0;i<H;i++){
        for(j=0;j<W;j++){
            cin >> s.at(i).at(j);
            if(s.at(i).at(j)=="snuke"){
                h=j;
                g=i+1;
            }
        }
    }
    t='A'+h;
    cout << t << g << endl;

    return 0;
}