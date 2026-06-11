#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const long long INF=INT_MAX/4;
const long long MOD=998244353;
const double EPS=1e-14;
const bool DEBUG=false;

const string YES = "YES";
const string NO = "NO";
const string Yes = "Yes";
const string No = "No";

template<class T>
void debug(T head){
    if(DEBUG){
        cout<<head<<endl;
    }
}

template <class Head, class... Body>
void debug(Head head, Body... body){
    if(DEBUG){
        cout<<head<<" ";
        debug(body...);
    }
}

/////
void answer(string S){
    int len = S.length();
    debug(len);
    for(int i=2; i<=len; i+=2){
        debug(S.substr(0, (len - i) / 2));
        debug(S.substr((len - i) / 2));
        debug(" ");
        if(S.substr(0, (len - i) / 2) == S.substr((len - i) / 2, (len - i) / 2)){
            cout<<len - i<<endl;
            break;
        }
    }
    return;
}

/////

int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.precision(16);

    string S;
    cin>>S;
    answer(S);

    return 0;
}
