#include<iostream>
using namespace std;

int main(){
    string a,b,c;
    cin >> a >> b >> c;
    bool ans = 0;
    int la = a.size();
    int lb = b.size();
    int lc = c.size();
    if((a.at(la - 1) == b.at(0))&&(b.at(lb - 1) == c.at(0))){
        ans = 1;
    }
    if(ans){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}