#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long int LLI;

string solve(vector <int> & start, unordered_map <int,int> & services, int & n )
{
    for(int i = 0; i < start.size(); i++)
        if( services[ start[i] ] == n )
            return "POSSIBLE";
    return "IMPOSSIBLE";
}
int main()
{
    int n, m, a, b;
    bool check = false;
    cin >> n >> m;
    unordered_map <int, int> services;
    vector <int> start;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if( a == 1 ){
            start.push_back(b);
            if( b == n )
                check = true;
        }else
            services[a] = b;
    }
    
    if( check == true )
        cout << "POSSIBLE";
    else
        cout << solve(start,services,n);
}