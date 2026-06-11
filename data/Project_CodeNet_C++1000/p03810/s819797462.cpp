//Be Name Khoda, Besmellah Rahmane Rahim, In The Name Of God;
//#include<bits/stdc++.h>
#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>
#include <stdio.h>
#include <string.h>
#include<iomanip>
#include<unordered_map>
#include<unordered_set>


 
using namespace std;

const int N = 1e5 + 5;
int a[N];
int n;
int odd = 0;
int even = 0;
int maxi = 0;
vector<int> board;
string ans[2];

void solver(vector<int> a, int turn)
{
    odd = 0;
    even = 0;
    maxi = 0;
    for (int i = 0; i < n; i++)
    {
        //cout << a[i] << " ";
        if (a[i] % 2)
        {
            odd++;
        }
        else
        {
            even++;
        }
        maxi = max(maxi, a[i]);
    }
    //cout << endl;
    if (maxi == 1)
    {
        cout << ans[(turn + 1) % 2] << endl;
        exit(0);
    }
    if (even % 2)
    {
        cout << ans[turn] << endl;
        exit(0);
    }
    if (odd >= 2)
    {
        cout << ans[(turn + 1) % 2] << endl;
        exit(0);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2)
        {
            if (a[i] == 1)
            {
                cout << ans[(turn + 1) % 2] << endl;
                exit(0);
            }
            a[i]--;
            int g = 0;
            for (int j = 0; j < n; j++)
            {
                g = __gcd(a[j], g);
            }
            for (int j = 0; j < n; j++)
            {
                a[j] = a[j] / g;
            }
            solver(a, (turn + 1) % 2);
        }
    }

}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        board.push_back(tmp);
    }   
    ans[0] = "First";
    ans[1] = "Second";
    solver(board, 0);
    


}
