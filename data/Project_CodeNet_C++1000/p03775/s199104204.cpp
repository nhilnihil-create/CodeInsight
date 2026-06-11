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
void answer(ll N){
    ll sqrt_N = floor(sqrt(N)), answer;
    debug(sqrt_N);
    for(int i=sqrt_N; i>=1; --i){
        if(N % i == 0){
            answer = log10(N/i) + 1;
            debug(i, N/i);
            break;
        }
    }
    cout<<answer<<endl;

    return;
}

/////

int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.precision(16);

    ll N;
    cin>>N;
    answer(N);

    return 0;
}
