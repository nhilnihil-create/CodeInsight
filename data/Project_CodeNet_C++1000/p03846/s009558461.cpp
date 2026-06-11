#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N;
    cin >> N;

    set<ll> st;
    map<ll,ll> mp;
    for(ll i = 0; i < N; i++)
    {
        ll tmp;
        cin >> tmp;
        mp[tmp]++;
        st.insert(tmp);
    }

    ll stIdx = 0;
    auto first = st.begin();
    ll count = 0;
    ll ans = 1;

    if(*first == 0)
    {
        for(auto e:mp)
        {
            if(e.first == 0)
            {
                if(e.second != 1)
                {
                    cout << 0 << endl;
                    return 0;
                }
            }
            else
            {
                if(e.second != 2)
                {
                    cout << 0 << endl;
                    return 0;
                }
            }
            

        }

        for(auto itr = st.begin(); itr != st.end(); itr++)
        {
            if(*itr != stIdx * 2)
            {
                cout << 0 << endl;
                return 0;
            }
            stIdx++;
            count++;
        }

        for(ll i = 1; i < count; i++)
        {
            ans *= 2;
            ans %= 1000000007;
        }
    }
    else
    {
        for(auto e:mp)
        {
            if(e.second != 2)
            {
                cout << 0 << endl;
                return 0;
            }
        }

        for(auto itr = st.begin(); itr != st.end(); itr++)
        {
            if(*itr != stIdx * 2 + 1)
            {
                cout << 0 << endl;
                return 0;
            }
            stIdx++;
            count++;
        }

        for(ll i = 1; i <= count; i++)
        {
            ans *= 2;
            ans %= 1000000007;
        }
    }
    
    cout << ans << endl;
    return 0;
    
    
}