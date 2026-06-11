#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
	int a,b;
    cin >> a >> b;
    if(a==1) a+=13;
    if(b==1) b+=13;
    if(a>b) cout << "Alice";
    else if(a<b) cout << "Bob";
    else cout << "Draw";
    
}