//Be Name Khoda, Besmellah Rahmane Rahim, In The Name Of God;
//#include<bits/stweight++.h>
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
#include <fstream>


using namespace std;
 
 
const int N = 505;
int a[N * N];
int check[N * N];
int b[N];
int num[N];
int n;

bool cmp(int i, int j)
{
    return b[i - 1] < b[j - 1];
}
 
int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i]--;
        num[i] = i + 1;
        a[b[i]] = i + 1;
    }
    sort(num, num + n, cmp);
    int i = 0;
    int j = 0;
    int cnt = 1;
    while (i < n)
    {
        while (a[j])
        {
            j++;
        }
        if (cnt + 1 <= num[i])
        {
            a[j] = num[i];
            cnt++;
        }
        if (cnt == num[i])
        {
            i++;
            cnt = 1;
        }
    }
    i = 0;
    j = 0;
    cnt = num[0];
    while (i < n)
    {
        while (a[j])
        {
            j++;
        }
        if (cnt + 1 <= n)
        {
            a[j] = num[i];
            cnt++;
        }
        if (cnt == n)
        {
            i++;
            cnt = num[i];
        }
    }
    j = 0;
    for (int i = 0; i < n * n; i++)
    {
        if (a[i] == 0)
        {
            cout << a[i] << endl;
        }
        check[a[i]]++;
        if (i == b[num[j] - 1])
        {
            if (check[num[j]] != num[j])
            {
                cout << "No" << endl;
                exit(0);
            }
            j++;
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n * n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;


 
 
 
 
}























