#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n,0);
    for(int i = 0; i < n; ++i){
        if(s[i]=='I') a[i]++;
        else a[i]--;
        if(i != 0) a[i] += a[i-1];
    }
    int xnum = 0;
    for(int num:a){
        xnum = max(xnum,num);
    }
    cout << xnum << endl;   
    return 0;
}