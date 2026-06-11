#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int n,m,temp,i;
    cin >> n;
    vector <int> a;
    i = 0;
    int sum = 0;
    while (n--){
        cin>> temp;
         a.push_back(temp);
        sum = sum+temp;
        }

    cin >> m;
    while (m--)
    {
        cin >> i >> temp;
        temp = temp - a[i-1];
        cout << sum + temp<<"\n";
    }
    return 0;
    }
