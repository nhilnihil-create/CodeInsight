#include <bits/stdc++.h>

#define pb push_back
#define all(c) c.begin(),c.end()
#define allr(c) c.rbegin(),c.rend()
#define MOD 1000000007
#define PI 3.14159265
#define endl '\n'
#define MAX 501

using namespace std;

void quick ()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);/*//*/
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int diva (int n)
{
    int counter = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        if (n%i==0)
            counter++;
    }
    return counter;
}

void readFromText()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
}

int main()
{
    quick();
//    readFromText();
    string s;  cin >> s;
	for (int i = 0;i < s.size()-1;i++) {
		if (s[i] == s[i + 1]) {
			cout << i + 1 << " " << i + 2 << endl;
			return 0;
		}
	}
	for (int i = 0; i < s.size()-2;i++) {
		if (s[i] == s[i + 2]) {
			cout << i + 1 << " " << i + 3 << endl;
			return 0;
		}
	}
	cout << -1 << " " << -1 << endl;
    return 0;
}
