#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;

char sn[2] = {' ', '\n'};

int main()
{	
    int n, x = 0, k = 0;
    string s;
    scanf("%d", &n);
    cin >> s;
    for(int i=0; i < (int)s.size();i++) {
        if(s.at(i) == 'I') k++;
        else k--;
        x = max(x,k);
    }
    printf("%d\n",x);
    return 0;
}
