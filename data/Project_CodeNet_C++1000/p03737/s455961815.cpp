#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

struct ToUpper {
    char operator()(char c) { return toupper(c); }
};

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    transform(s1.begin(), s1.end(), s1.begin(), ToUpper());
    dump(s1);

    transform(s2.begin(), s2.end(), s2.begin(), ToUpper());
    transform(s3.begin(), s3.end(), s3.begin(), ToUpper());

    char tmp1 = s1.at(0);
    char tmp2 = s2.at(0);
    char tmp3 = s3.at(0);

    cout << s1.at(0) << tmp2 << tmp3 << endl;

    return 0;
}
