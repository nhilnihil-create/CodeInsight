#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int a,b;
    cin >> a >> b;
    vector<string> vec;
    for(int i=0; i<a; i++){
        string s;
        cin >> s;
        vec.push_back(s);
    }
    for(int i =0; i<vec.size(); i++){
        cout << vec[i] <<endl;
        cout << vec[i] <<endl;
    }
}