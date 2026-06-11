#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >>s;
    int cn=0, cw=0, cs=0, ce=0;
    for (int i=0; i < s.size(); i++) {
        if (s.at(i)=='N') cn++;
        if (s.at(i)=='W') cw++;
        if (s.at(i)=='S') cs++;
        if (s.at(i)=='E') ce++;
    }
    string ret = "No";

    if (cn>0  && cs>0  && cw>0  && ce>0)  {ret = "Yes";}
    if (cn==0 && cs==0 && cw>0  && ce>0)  {ret = "Yes";}
    if (cn>0  && cs>0  && cw==0 && ce==0) {ret = "Yes";}

    cout << ret << endl;
    return 0;
}