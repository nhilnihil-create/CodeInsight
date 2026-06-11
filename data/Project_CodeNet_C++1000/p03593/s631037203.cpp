#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define rep(i,n) for(int i=0;i<n;i++)

int H, W;
int mem[50];

signed main()
{
    cin >> H >> W;
    rep(i, H)rep(j, W)
    {
        char c;
        cin >> c;
        mem[c - 'a']++;
    }

    int N = 'z' - 'a' + 1;
    if(H % 2 && W % 2)
    {
        rep(i, N)
        {
            if(mem[i] % 2)
            {
                mem[i]--;
                break;
            }
        }
        rep(i, (H / 2) * (W / 2))
        {
            rep(j, N)if(mem[j] >= 4)
            {
                mem[j] -= 4;
                break;
            }
        }
        rep(i, H / 2 + W / 2)
        {
            rep(j, N)if(mem[j] >= 2)
            {
                mem[j] -= 2;
                break;
            }
        }
        rep(i, N + 1)
        {
            if(i == N)
            {
                cout << "Yes" << endl;
                return 0;
            }
            if(mem[i] != 0)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    
    if(W % 2  == 1 && H % 2 == 0)swap(H, W);
    if(H % 2 && W % 2 == 0)
    {
        rep(i, (H / 2) * (W / 2))
        {
            rep(j, N)if(mem[j] >= 4)
            {
                mem[j] -= 4;
                break;
            }
        }
        rep(i, W / 2)
        {
            rep(j, N)if(mem[j] >= 2)
            {
                mem[j] -= 2;
                break;
            }
        }
        rep(i, N + 1)
        {
            if(i == N)
            {
                cout << "Yes" << endl;
                return 0;
            }
            if(mem[i] != 0)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    rep(i, H * W / 4)
    {
        rep(j, N)if(mem[j] >= 4)
        {
            mem[j] -= 4;
            break;
        }
    }
    rep(i, N + 1)
    {
        if(i == N)
        {
            cout << "Yes" << endl;
            return 0;
        }
        if(mem[i] != 0)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    return 0;
}