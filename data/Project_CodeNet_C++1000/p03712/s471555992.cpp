#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >>H>>W;
    vector<vector<char>>vec(H,vector<char>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >>vec.at(i).at(j);
        }
    }
    for(int i=0;i<=W+1;i++){
        cout <<'#';
    }
    cout <<endl;
    for(int i=0;i<H;i++){
     cout <<'#';
     for(int j=0;j<W;j++){
         cout<<vec.at(i).at(j);
     }
     cout<<'#'<<endl;
    }
    for(int i=0;i<=W+1;i++){
        cout <<'#';
    }
    cout <<endl;
}