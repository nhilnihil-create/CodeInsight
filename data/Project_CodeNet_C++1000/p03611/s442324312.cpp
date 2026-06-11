#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> a(N);
    
    int len = 1e5;
    vector<int> vals(len);

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        vals[a[i]]++;
    }

    int min = *min_element(a.begin(), a.end());
    int max = *max_element(a.begin(), a.end());
    
    int maxCount = 0;
    for(int x = min; x <= max; x++){
        int left = (x > 0) ? vals[x-1] : 0;
        int right = (x < len - 1) ? vals[x+1] : 0;
        int count = left + vals[x] + right;
        if(count > maxCount) maxCount = count;
    }

    cout << maxCount << endl;
    return 0;
}
