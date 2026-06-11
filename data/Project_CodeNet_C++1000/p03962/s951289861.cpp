#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> vi;

ifstream fin("parimpar2.in");
ofstream fout("parimpar2.out"); 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
   
    int a, b, c;
    cin >> a >> b >> c;
    if(a==b && b==c)
        cout << 1;
    else if(a==b)
        cout << 2;
    else if(a==c)
        cout << 2;
    else if(b==c)
        cout << 2;
    else
        cout << 3;
    return 0;
}
