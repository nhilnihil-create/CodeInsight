#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<numeric>

using namespace std;

int main() {

    string s; cin>>s;


    bool f{};
    for (int i = 1; i < s.size(); ++ i) {
        if (s[i] == s[i-1]) {
            cout<<i<<" " << i+1<<endl;
            f=true;
            break;
        }
        else if (i+1<s.size() && s[i-1] == s[i+1]) {
            cout<<i<<" " << i+2<<endl;
            f=true;
            break;
        }
    }
    if (!f) cout<<"-1 -1"<<endl;

    return 0;
}
