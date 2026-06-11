//
// Created by GGG1235 on 2019/11/24.
//

#include <bits/stdc++.h>

#pragma GCC optimize(3)

using namespace std;

typedef long long LL;

int main(int argc,const char **argv,const char **envp) 
{
    ios::sync_with_stdio(false);
    cin.tie();
    
    string szInput;
    
    int nLength = 0;
    int nTmp   = 0;
    
    cin >> szInput;
    nLength = static_cast<int>(szInput.length());
    for (int i = 0; i < nLength; ++i)
    {
        if (szInput[i] == 'g')
        {
            nTmp++;
        }
    }
    cout << min(nLength / 2, nTmp) - min(nLength - nLength / 2, nLength - nTmp) << endl;
    return 0;
}