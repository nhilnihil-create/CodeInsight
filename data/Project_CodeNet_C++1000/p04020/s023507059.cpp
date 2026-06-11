#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

void ALLIN1_NUMBER(vector<ll>& V)
{
    for(auto& x : V)
    {
        cin >> x;
    }
}

void ALLOUT_NUMBER(vector<ll> V)
{
    ll N = V.size();
    for(ll i=0;i<N;i++)
    {
        cout << V[i];
        if(i<N-1) cout << ' ';
    }
    cout << endl;
}

template<class T>
void OUT0(T N)
{
    cout << N << endl;
}

static const double pi = acos(-1.0);

double Cos(double D)
{
    return cos(pi/180 * D);
}

vector<ll> Reduced(ll N, vector<ll> A)
{
    vector<ll> B = A;    
    for(ll i=0;i<N-1;i++)
    {
        B[i]%=2;
        if(B[i+1]!=0)
        {
            B[i+1]-=B[i];
            B[i]=0;
        }
    }
    B[N-1]%=2;
    return B;
}

int main()
{
    ll N;
    cin >> N;

    vector<ll> A(N);
    ALLIN1_NUMBER(A);

    vector<ll> reduced_A = Reduced(N,A);

    OUT0((accumulate(ALL(A),0LL)-accumulate(ALL(reduced_A),0LL))/2);

    return 0;
}