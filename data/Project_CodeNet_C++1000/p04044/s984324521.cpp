#include <bits/stdc++.h>

using namespace std;




int main(void)
{
    string tmp,ans="";
    vector<string> vec;
    int N,L;

    cin>>N>>L;

    for(int i=0;i<N;i++){
        cin>>tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(),vec.end());

    for(int i=0;i<vec.size();i++){
        ans+=vec[i];
    }

    cout<<ans<<endl;


	return 0;
}
