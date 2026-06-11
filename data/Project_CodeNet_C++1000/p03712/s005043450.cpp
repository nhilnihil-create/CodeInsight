#include <bits/stdc++.h>
using namespace std;
 
int main()
{
int A,B;
cin >> A >> B;
vector<char> S(A*B);
for(int i=0; i<A*B; i++)
{
    cin >> S.at(i);
}
int count=0;
for(int i=0; i<A+2; i++)
{
    for(int j=0; j<B+2; j++)
    {
        if(!(i==0||i==A+1)&&!(j==0||j==B+1))
        {
            cout << S.at(count);
            count++;
        }
        else
        {
            cout << "#";
        }
        if(j==B+1) cout << endl;
    }
}
}