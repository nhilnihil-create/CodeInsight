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

vector<ll> make_groups(ll N, vector<ll> A)
{
    vector<ll> ret;
    for(ll i=0;i<N;i++)
    {
        ll add = 0;
        for(ll& j=i;j<N;j++)
        {
            if(A[j]==0)
            {
                break;
            }
            add += A[j];
        }
        ret.push_back(add);
    }
    return ret;
}

ll Ans(vector<ll> groups)
{
    ll ret = 0;
    for(auto x : groups)
    {
        ret += x/2;
    }
    return ret;
}

int main()
{
    ll N;
    cin >> N;

    vector<ll> A(N);
    ALLIN1_NUMBER(A);

    OUT0(Ans(make_groups(N,A)));

    return 0;
}