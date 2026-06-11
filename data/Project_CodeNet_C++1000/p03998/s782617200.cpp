#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
int main()
{
    string a,b,c;
    cin >> a;
    cin >> b;
    cin >> c;
    char user = 'a';
    int size = a.size()+b.size()+c.size();
    rep(i, size){
        // cout << user <<endl;
        if(user=='a'){
            if(a.size() == 0) {user = 'a'; break;}
            user = a[0];
            a.erase(0,1);
        }else if(user=='b'){
            if(b.size() == 0) {user = 'b'; break;}
            user = b[0];
            b.erase(0,1);
        }else if(user=='c'){
            if(c.size() == 0) {user = 'c'; break;}
            user = c[0];
            c.erase(0,1);
        }
    }
    if(user=='a'){
        cout << 'A' << endl;
    }else if(user=='b'){
        cout << 'B' << endl;
    }else if(user=='c'){
        cout << 'C' << endl;
    }

    return 0;
}