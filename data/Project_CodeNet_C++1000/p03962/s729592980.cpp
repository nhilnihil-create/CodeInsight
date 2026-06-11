#include <bits/stdc++.h>

using namespace std;




int main(void)
{
    int tmp;
    set<int> colors;

    for(int i=0;i<3;i++){
        cin>>tmp;
        colors.insert(tmp);
    }


    cout<<colors.size()<<endl;

	return 0;
}
