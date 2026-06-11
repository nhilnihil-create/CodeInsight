#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N; cin >> N;
    vector<int> a(N);
    map<string, int> color;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        if(a[i] < 400) {
            if(!color.count("gray")) color["gray"] = 1;
            else color["gray"]++;
        }
        else if(a[i] < 800) {
            if(!color.count("brown")) color["brown"] = 1;
                else color["brown"]++;
        }
        else if(a[i] < 1200) {
            if(!color.count("green")) color["green"] = 1;
            else color["green"]++;
        }
        else if(a[i] < 1600) {
            if(!color.count("cyan")) color["cyan"] = 1;
            else color["cyan"]++;
        }
        else if(a[i] < 2000) {
            if(!color.count("blue")) color["blue"] = 1;
            else color["blue"]++;
        }
        else if(a[i] < 2400) {
            if(!color.count("yellow")) color["yellow"] = 1;
            else color["yellow"]++;
        }
        else if(a[i] < 2800) {
            if(!color.count("orange")) color["orange"] = 1;
            else color["orange"]++;
        }
        else if(a[i] < 3200) {
            if(!color.count("red")) color["red"] = 1;
            else color["red"]++;
        }
        else {
            if(!color.count("free")) color["free"] = 1;
            else color["free"]++;
        }
    }
    if(!color.count("free")) cout << color.size() << ' ' << color.size() << endl;
    else cout << max(1, (int)color.size() - 1) << ' ' << color.size() - 1 + color["free"] << endl;
    return 0;
}