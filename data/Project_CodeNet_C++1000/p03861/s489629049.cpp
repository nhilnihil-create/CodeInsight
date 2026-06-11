#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const long long INF=INT_MAX/4;
const long long MOD=1'000'000'007;
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
    unsigned long long a, b, x;
    cin>>a>>b>>x;
    if(x==1){
        cout<<b-a+1<<endl;
        return;
    }
    if(a==0){
        cout<<b/x + 1<<endl;
        return;
    }
    if(a==b){
        if(a%x==0){
            cout<<1<<endl;
            return;
        }
    }
    cout<<(b/x+1) - ((a-1)/x+1)<<endl;

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
