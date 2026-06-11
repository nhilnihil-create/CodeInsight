#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string ans;
    int x1, y1, x2, y2;
    int nx, ny;
    cin>>x1>>y1>>x2>>y2;
    nx = x2-x1;
    ny = y2-y1;

    for(int i=0;i<ny;i++) ans.push_back('U');
    for(int i=0;i<nx;i++) ans.push_back('R');
    for(int i=0;i<ny;i++) ans.push_back('D');
    for(int i=0;i<nx;i++) ans.push_back('L');

    ans.push_back('L');
    for(int i=0;i<ny+1;i++) ans.push_back('U');
    for(int i=0;i<nx+1;i++) ans.push_back('R');
    ans.push_back('D');
    ans.push_back('R');
    for(int i=0;i<ny+1;i++) ans.push_back('D');
    for(int i=0;i<nx+1;i++) ans.push_back('L');
    ans.push_back('U');
    cout<<ans<<endl;

}
