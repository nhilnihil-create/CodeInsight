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

map<char,ll> Char_Counter(string s)
{
    map<char,ll> ret;
    for(auto x : s)
    {
        ret[x]++;
    }
    return ret;
}

void ALLOUT_MAP(map<char,ll> Map)
{
    for(auto x : Map)
    {
        cout << x.first << ' ' << x.second << endl; 
    }
}

void Ans(string s, map<char,ll> number_of_chars)
{
    ll ans = s.size()*(s.size()-1)/2;
    for(auto x : number_of_chars)
    {
        ans -= x.second*(x.second-1)/2;
    }
    OUT0(ans+1);
}

int main()
{
    string s;
    cin >> s;

    map<char,ll> number_of_chars = Char_Counter(s);

    Ans(s,number_of_chars);

    return 0;
}