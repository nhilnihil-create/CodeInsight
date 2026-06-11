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
void answer(ll N, vector<ll> A){
    ll answer = 0;
    for(auto &a : A){
        if(a >= 3){
            if(a % 2 == 0){
                answer += (a - 2) / 2;
                a = 2;
            }else{
                answer += a / 2;
                a = 1;
            }
        }
    }

    for(int i=0; i<A.size()-1; ++i){
        if(A[i] == 2){
            A[i] == 0;
            answer++;
        }else if(A[i]==1 && A[i+1]>=1){
            A[i] = 0;
            A[i+1] -= 1;
            answer++;
        }
    }
    if(A[A.size()-1]>=2){
        A[A.size()-1] = 0;
        answer++;
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
    vector<ll> A(N);
    for(auto &a : A){
        cin>>a;
    }
    answer(N, A);

    return 0;
}
