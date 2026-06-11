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
void answer(){
    long H, W;
    cin>>H>>W;

    for(int i=0; i<W+2; ++i){
        cout<<"#";
    }
    cout<<endl;

    string s;
    for(int i=0; i<H; ++i){
        cin>>s;
        cout<<"#" + s + "#"<<endl;
    }

    for(int i=0; i<W+2; ++i){
        cout<<"#";
    }
    cout<<endl;

    return;
}

/////

int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.precision(16);

    answer();

    return 0;
}
