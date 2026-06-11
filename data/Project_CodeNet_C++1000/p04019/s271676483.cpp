#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;

int main(){
    string S;
    cin >> S;
    if(S.find("N")!=string::npos&&S.find("S")==string::npos) cout << "No" << endl;
    else if(S.find("S")!=string::npos&&S.find("N")==string::npos) cout << "No" << endl;
    else if(S.find("E")!=string::npos&&S.find("W")==string::npos) cout << "No" << endl;
    else if(S.find("W")!=string::npos&&S.find("E")==string::npos) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
    
}