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

void As(string& s, ll& K)
{
    for(auto& x : s)
    {
        if(x!='a')
        if(('z'+1-x)<=K)
        {
            K -= ('z'+1-x);
            x = 'a';
        }
    }
    K%=('z'-'a'+1);
    for(ll i=0;i<K;i++)
    {
        if(s[s.size()-1]=='z') s[s.size()-1] = 'a';
        else s[s.size()-1]++;
    }
}

int main()
{
    string s;
    cin >> s;

    ll K;
    cin >> K;

    As(s,K);

    OUT0(s);

    return 0;
}