#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    string S;
    cin >> N;
    cin >> S;

    int sum = 0;
    string head = "";
    string tail = "";

    for(int i=0;i<N;++i)
    {
        if (S[i]=='(')
        {
            sum += 1;
        }
        if (S[i]==')')
        {
            sum -= 1;
        }
        if (sum < 0)
        {
            head += "(";
            sum++;
        }
    }
    while(sum>0)
    {
        tail += ")";
        sum--;
    }

    cout << head << S << tail << endl;

    return 0;
}
