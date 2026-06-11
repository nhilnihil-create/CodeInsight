#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<bool> color(8, false);
    int rate, cnt = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> rate;
        if(rate < 400)  color[0] = true;
        else if(rate < 800)  color[1] = true;
        else if(rate < 1200) color[2] = true;
        else if(rate < 1600) color[3] = true;
        else if(rate < 2000) color[4] = true;
        else if(rate < 2400) color[5] = true;
        else if(rate < 2800) color[6] = true;
         else if(rate < 3200) color[7] = true;
        else if(rate >= 3200)   cnt++;
    }
    cout<<max(accumulate(color.begin(),color.end(),0),1)<<" "<<accumulate(color.begin(),color.end(),0)+cnt<<endl;
	return 0;
}