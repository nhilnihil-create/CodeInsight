#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }


int main(){
    string Sa,Sb,Sc;
    cin >> Sa >> Sb >> Sc;

    char c = Sa[0];
    Sa.erase(0,1);
    if(Sa.size() == 0){
        cout << 'A' << endl;
        return 0;
    }



    while(1){
        if(c == 'a'){
            if(Sa.size() == 0){
                cout << 'A' << endl;
                return 0;
            }
            c = Sa[0];
            Sa.erase(0,1);
        }else if(c == 'b'){
            if(Sb.size() == 0){
                cout << 'B' << endl;
                return 0;
            }
            c = Sb[0];
            Sb.erase(0,1);
        }else{
            if(Sc.size() == 0){
                cout << 'C' << endl;
                return 0;
            }
            c = Sc[0];
            Sc.erase(0,1);
        }
    }
}
