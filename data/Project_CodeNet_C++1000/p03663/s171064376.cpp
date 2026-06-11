#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define size(n) ( int( n.size() ) )
#define sqr(n) ( (n) * (n) )
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;

string ans, curRes = "", s, tmp;
int len;

void ask( string query ){
    cout << "? " << query << endl;
    cin >> ans;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    tmp = "1";
    for ( int i = 1; i <= 10; i++ ){

        ask(tmp);
        if ( ans == "N" ){
            len = i - 1;
            break;
        }
         tmp = tmp + "0";
    }
    tmp = "1";
    for ( int i = 1; i <= 10; i++ ){
        tmp = tmp + "0";
    }
    ask(tmp);
    if ( ans == "Y" ){
        int i;
        for ( i = 9; i >= 0; i-- ){
            tmp.erase( tmp.begin() + size(tmp) - 1 );
            tmp.erase( tmp.begin() + size(tmp) - 1 );
            tmp = tmp + "1";
            ask(tmp);
            if ( ans == "N" ){
                len = i + 2;
                break;
            }
        }
        if ( i == -1 ){
            ask("2");
            if ( ans == "Y" ){
                cout << "! 1" << endl;
            }
            else{
                cout << "! 10" << endl;
            }
            return 0;
        }
    }
    for ( int i = 1; i <= len - 1; i++ ){
        int low = 0, high = 10, mid;
        while( high - low > 1 ){
            mid = ( high + low ) >> 1;
            s = mid + '0';
            ask( curRes + s );
            if ( ans == "Y" ){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        s = low + '0';
        curRes = curRes + s;
    }
    for ( int i = 0; i <= 9; i++ ){
        if ( size(curRes) == 0 && i == 0 ){
            continue;
        }
        s = i + '0';
        s = s + "0";
        ask( curRes + s );
        if ( ans == "Y" ){
            s = i + '0';
            curRes = curRes + s;
            break;
        }
    }
    cout << "! " << curRes << endl;
    return 0;
}

