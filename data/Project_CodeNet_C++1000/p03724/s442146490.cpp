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

bool ans_bool(int M)
{
    map<int,int> counter;
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin >> a >> b;

        counter[a]++;
        counter[b]++;
    }

    bool ans = true;

    for(auto x : counter)
    {
        if(x.second%2!=0) ans = false;
    }

    return ans;
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

int main()
{
    ll N,M;
    cin >> N >> M;

    bool ans = ans_bool(M);

    if(ans) OUT0("YES");
    else OUT0("NO");

    return 0;
}