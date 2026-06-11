#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"

using namespace std;

//ll const N = 32000;
int cnt[26];

int main()
{
    string w;
    int flag = 0;

    cin >> w;

    for(int i = 0; i < w.size(); i++)
    {
        cnt[w[i] - 97]++;
    }


    for(int i = 0; i < 26; i++)
    {
        if(cnt[i] % 2 != 0)
        {
            flag++;
            break;
        }
    }

    if(flag == 0)printf("Yes\n");
    else printf("No\n");

    return 0;
}