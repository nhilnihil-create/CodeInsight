#include <bits/stdc++.h>
//#include <map>
//#include <set>
//#include <list>
//#include <cmath>
//#include <ctime>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <string>
//#include <bitset>
//#include <cstdio>
//#include <limits>
//#include <vector>
//#include <climits>
//#include <cstring>
//#include <cstdlib>
//#include <fstream>
//#include <numeric>
//#include <sstream>
//#include <iomanip>
//#include <iostream>
//#include <algorithm>
//#include <unordered_map>

using namespace std;

#define file freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define PI 3.141592653589793238462643383279502884
#define MAX 1000100
#define mod 1000000007
#define EPS 1E-9
#define int long long
#define endl "\n"

int fix(int cur, int m)
{
    return ((cur%m) + m) % m;
}

int fast_power(int x, int y,int m)
{
    if (y == 0)
        return 1;
    int temp = fast_power(x, y / 2, m) ;
    temp = (temp*temp)% m;
    if (y % 2 != 0)
        temp = (temp*x)% m;
    return temp;

}
bool check(string str)
{
    set<char>st;
    for(int i=0;i<str.size();i++)
    {
        st.insert(str[i]);
    }
    return (st.size()!=3);
}

int32_t main()
{
    //freopen("C:/Users/Joe/Desktop/tests/in11.txt", "r", stdin);
    //freopen("C:/Users/Joe/Desktop/tests/out11.txt", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.tie(0);

    int t=1;
    //cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        int s=-1,e=-1;
        if(str.size()==2)
        {
            if(str[0]==str[1])
                cout << 1 << " " << 2 << endl;
            else
                cout << -1 << " " << -1 << endl;
            return 0;
        }
        for(int i=0;i<str.size()-2;i++)
        {
            if(str[i]==str[i+2])
            {
                s=i,e=i+2;
                break;
            }
            else if(str[i]==str[i+1])
            {
                s=i,e=i+1;
                break;
            }
        }
        if(s==-1 && e==-1)
            return cout << -1 << " " << -1 << endl,0;
        cout << s+1 << " " << e+1 << endl;



    }
    return 0;
}
