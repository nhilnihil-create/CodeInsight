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

void Reduce_Each_to_x(vector<ll>& Candies, ll x)
{
    for(auto& y : Candies)
    {
        y = min(x,y);
    }
}

void Reduce_Each_to_Ans(ll N, vector<ll>& Candies, ll x)
{
    for(ll i=1;i<N;i++)
    {
        Candies[i] -= max(Candies[i-1]+Candies[i]-x,0LL);
    }
}

int main()
{
    ll N,x;
    cin >> N >> x;

    vector<ll> Candies(N);
    ALLIN1_NUMBER(Candies);
    vector<ll> Candies_def_copy = Candies;

    Reduce_Each_to_x(Candies,x);
    Reduce_Each_to_Ans(N,Candies,x);

    OUT0(accumulate(ALL(Candies_def_copy),0LL)-accumulate(ALL(Candies),0LL));

    return 0;
}