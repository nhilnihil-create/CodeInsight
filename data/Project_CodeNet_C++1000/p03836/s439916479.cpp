#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define ll unsigned long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define forn(b) for(int i = 0; i < b; i++)
#define rforn(b) for(int i = b - 1 ;i >= 0; i--)
#define It(m) for(auto it = m.begin(); it != m.end(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
const ll mod = (ll)1e9 + 7;
    
int main() {
	speed;
    int x, y, tx, ty; cin >> x >> y >> tx >> ty;
    int x1 = x, y1 = y;
    string s1 = "", s2 = "", s3 = "", s4 = "";
    while(x != tx) {
        s1 += 'R';
        s2 += 'L';
        x++;
    }
    while(y != ty) {
        s1 += 'U';
        s2 += 'D';
        y++;
    }
    s3 += 'D';
    s4 += 'U';
    while(x1 != tx + 1) {
        s3 += 'R';
        s4 += 'L';
        x1++;
    }
    while(y1 != ty + 1) {
        s3 += 'U';
        s4 += 'D';
        y1++;
    }
    s3 += 'L';
    s4 += 'R';
    cout << s1 + s2 + s3 + s4 << endl;

}
