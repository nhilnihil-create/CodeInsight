#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char dfs(char nxt, string &A, string &B, string &C, int &acnt, int &bcnt, int &ccnt)
{
    char res;
    if(nxt == 'a')
    {
        acnt++;
        if(acnt == A.length()) return 'A';
        res = dfs(A[acnt], A, B, C, acnt, bcnt, ccnt);
    }
    else if(nxt == 'b')
    {
        bcnt++;
        if(bcnt == B.length()) return 'B';
        res = dfs(B[bcnt], A, B, C, acnt, bcnt, ccnt);
    }
    else if(nxt == 'c')
    {
        ccnt++;
        if(ccnt == C.length()) return 'C';
        res = dfs(C[ccnt], A, B, C, acnt, bcnt, ccnt);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string A, B, C;
    cin >> A >> B >> C;

    int acnt = 0;
    int bcnt = -1;
    int ccnt = -1;

    cout << dfs('a', A, B, C, acnt, bcnt, ccnt) << endl;

    return 0;
}
