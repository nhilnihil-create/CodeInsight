#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};


int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    bool hai=false,cha=false,mido=false,mizu=false,ao=false,ki=false,tou=false,aka=false;
    int freee=0;

    rep(i,n){
        if(1<=a[i]&&a[i]<=399) hai=true;
        else if(400<=a[i]&&a[i]<=799) cha=true;
        else if(800<=a[i]&&a[i]<=1199) mido=true;
        else if(1200<=a[i]&&a[i]<=1599) mizu=true;
        else if(1600<=a[i]&&a[i]<=1999) ao=true;
        else if(2000<=a[i]&&a[i]<=2399) ki=true;
        else if(2400<=a[i]&&a[i]<=2799) tou=true;
        else if(2800<=a[i]&&a[i]<=3199) aka=true;
        else if(3200<=a[i]) freee++;
    }
    int MIN = 0;
    if(hai) MIN++;
    if(cha) MIN++;
    if(mido) MIN++;
    if(mizu) MIN++;
    if(ao) MIN++;
    if(ki) MIN++;
    if(tou) MIN++;
    if(aka) MIN++;
    if(MIN==0){
        cout << 1 << " " << freee << endl;
        return 0;
    }

    cout << MIN << " " << MIN+freee << endl;
}
