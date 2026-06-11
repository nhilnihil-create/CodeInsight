#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
int main() {
string s;
cin>>s;
string word[4] = {"remaerd", "maerd", "esare", "resare"};
reverse(s.begin(), s.end());
ll cnt = 0;
bool flag = true;
while (cnt < s.size()){
    if (s.substr(cnt, 5) == word[1]) cnt += 5;
    else if(s.substr(cnt,5)==word[2])
        cnt += 5;
    else if(s.substr(cnt,7)==word[0])
        cnt += 7;
    else if(s.substr(cnt,6)==word[3])
        cnt += 6;
    else {
        flag=false;
        break;
    }
}
cout << (flag ? "YES" : "NO") << endl;
}
