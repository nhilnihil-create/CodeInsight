#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int x, p;
};
bool cmp(Node a, Node b)
{
   return  a.x < b.x;
}
int main()
{   
 	Node a[100005], b[100005];
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x;
        a[i].p = i;
    }
    
    sort(a+1,a+n+1,cmp); //默认降序，cmp改为升序 
    
	int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if( abs(a[i].p-i) % 2 != 0) ans++;
    }
    
    cout << ans/2 << endl;
    
    return 0;
}