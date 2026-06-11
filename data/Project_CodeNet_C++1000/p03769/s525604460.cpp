#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
using namespace std;
typedef long long ll;
#define N  100005
//week_10_A
//我看网上代码看了很久也没反应过来，然后战略性放弃
//别想了，我就是代码的搬运工（我终于搞懂这道题这么写了）
//这道题大概是这样的, 记f为这个string中有的好串个数
//则f(c+X+c+Y) = 2*f(X+Y) + 1
//f(c+X+Y+c) = f(X+Y) + 1;
deque<int> L, R;
int num;
void sove_A( ll n)
{
    if(!n) return;
    //n是奇数时
    else if(n & 1)
    {
        sove_A(n>>1);
        L.push_front(++num);
        R.push_front(num);
    }
    else
    {
        sove_A(n-1);
        L.push_front(++num);
        R.push_back(num);
    }
}
void week_10_A()
{
    ll n;
    cin >> n;
    sove_A(n);
    cout << L.size()+R.size() << endl;
    cout << L.front();
    L.pop_front();
    while(!L.empty())
    {
        cout << ' ' << L.front();
        L.pop_front();
    }
    while(!R.empty())
    {
        cout << ' ' << R.front();
        R.pop_front();
    }
}
int main(int argc, const char * argv[])
{
    ios::sync_with_stdio();
    cin.tie(0);
    week_10_A();
    return 0;
}