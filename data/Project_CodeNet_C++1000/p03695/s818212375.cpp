#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
int main(){
    int n;
    cin >> n;
    set<int> s;
    int gm = 0;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;

        if(x < 3200)
            s.insert(x/400);
        else
            gm++;
    }

    if(gm == n)
        cout << 1 << " " << gm;
    else
        cout << s.size() << " " << s.size()+gm;

}