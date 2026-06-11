#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define Opy ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

typedef long long ll;

int main()
{
    map< char, int > A;
    A.clear();

    char B[110];

    cin>> B;

    for(int i = 0; i < strlen(B); i++)
    {
        A[B[i]]++;
    }

    int flag = 0;

    auto it = A.begin();

    while(it != A.end())
    {
        if(it->second % 2 != 0)
        {
            flag = 1;
            break;
        }
        it++;
    }

    if(flag == 0) cout<< "Yes\n";

    else cout<< "No\n";

	return 0;
}
