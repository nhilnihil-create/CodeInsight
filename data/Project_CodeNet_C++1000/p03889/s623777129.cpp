#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int i, s=0, n;
    string mir; 
    cin >> mir;
    n = mir.size();
    for(i=0;i<n/2;i++)
    {
        if(mir[i]=='b' && mir[n-i-1]=='d') s++;
        if(mir[i]=='d' && mir[n-i-1]=='b') s++;
        if(mir[i]=='p' && mir[n-i-1]=='q') s++;
        if(mir[i]=='q' && mir[n-i-1]=='p') s++;               
    }
    if(s == n/2 && n%2==0) cout << "Yes" << endl;
    else cout << "No" << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
