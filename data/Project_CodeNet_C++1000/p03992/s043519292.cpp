#include<bits/stdc++.h>
using namespace std;

int main(){
    using namespace std;
    string s;
    cin >> s;
    auto it = ostream_iterator<char>(cout);
    copy(s.begin(), s.begin() + 4, it);
    cout << " ";
    copy(s.begin() + 4, s.end(), it);
    cout << endl;
}