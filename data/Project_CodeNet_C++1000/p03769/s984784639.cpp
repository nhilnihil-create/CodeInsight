#include<iostream>
#include<vector>
using namespace std;
vector<int> l,r;
int main()
{
    int size1=0, size2=0, value=100;
    long long n;
    cin >> n;
    n++;
    while(n > 1)
    {
        if(n & 1) {
            l.push_back(value);
            size1 ++;
            n--;
        }
        else {
            r.push_back(value);
            n>>=1;
            size2 ++;
        }
    value--;
    }
    cout << (size1+size2<<1) << endl;
    for(int i=0; i<size1; i++)
        cout << l[i] << ' ';
    for(int i=size2-1; i>=0; i--)
        cout << r[i] << ' ';
    for(int i=101-size1-size2; i<101; i++)
        cout << i << ' ';
    return 0;
}