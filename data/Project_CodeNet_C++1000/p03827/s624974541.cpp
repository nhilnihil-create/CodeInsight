#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n;
    cin >> n >> s;
    int ans = 0, memo = 0;
    for(int i = 0;i < n;i++){
        if(s.at(i) == 'I')memo++;
        else memo--;
        if(memo >= ans)ans = memo;
    }
    cout << ans << endl;
}