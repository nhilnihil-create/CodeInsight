//Where's Snuke?
#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin>>H>>W;
    vector<vector<string>>box(H,vector<string>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>box.at(i).at(j);
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(box.at(i).at(j)=="snuke"){
                printf("%c%d\n",'A'+j,1+i);
                goto out;
            }
        }
    }
    out:
        return 0;
}