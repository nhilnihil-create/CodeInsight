#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int sx,sy,tx,ty;


bool viz[2009][2009];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>sx>>sy>>tx>>ty;

    string res;


    //X
    for (int i=0; i<abs(tx-sx); i++) {
	res+='R';
    }
    

    //Y
    for (int i=0; i<abs(ty-sy); i++) {
	res+='U';
    }



    res+='U';

    //X
    for (int i=0; i<abs(tx-sx); i++) {
	res+='L';
    }

    res+='L';

    //Y
    for (int i=0; i<abs(ty-sy); i++) {
	res+='D';
    }

    res += 'D';
    res += 'R';






    //Y
    for (int i=0; i<abs(ty-sy); i++) {
	res+='U';
    }
    
    //X
    for (int i=0; i<abs(tx-sx); i++) {
	res+='R';
    }
    




    
    res += 'R';
    for (int i=0; i<abs(ty-sy); i++) {
	res+='D';
    }
    res+='D';
    for (int i=0; i<abs(tx-sx); i++) {
	res+='L';
    }
    res+='L';
    res+='U';
    cout<<res<<endl;


    return 0;

    int x=sx;
    int y=sy;
    for (char c :res) {
	if (c=='R') x++;
	if (c=='L') x--;
	if (c=='U') y++;
	if (c=='D') y--;
	cout<<x<<" "<<y<<endl;
    }
    return 0;
}
