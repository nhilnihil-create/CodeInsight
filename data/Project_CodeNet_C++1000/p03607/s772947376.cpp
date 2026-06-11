#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    long int n;
    cin >> n;

    vector <long int> vec;
    long int input;

    for(long int i=0; i<n; i++)
    {
        cin >> input;
        vec.push_back(input);
    }

    sort(vec.begin(),vec.end());

    for(long int j=1; j<vec.size(); j++)
    {
        if(vec[j] == vec[j-1])
        {
            vec.erase(vec.begin() + (j - 1));
            vec.erase(vec.begin() + (j - 1));

            j--;
        }
    }

    cout << vec.size();
    return 0;
}
