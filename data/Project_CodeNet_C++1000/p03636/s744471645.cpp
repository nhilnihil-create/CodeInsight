#include <bits/stdc++.h>
using namespace std;

string s, ans;

int main(){
    cin>>s;

    int num = s.size();

    cout << s[0] << num - 2 << s[num-1]<<endl;
    return 0;
}
