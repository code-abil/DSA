#include<bits/stdc++.h>
using namespace std;
main()
{
    vector<int>a{1,1,1,2,2,3,3,5};
    // for(int x:a)
    //     cout<<x<<" ";
    // for(int i=0;i<=6;i++)
    // {
    //     auto x=lower_bound(a.begin(),a.end(),i);
    //     cout<<x-a.begin()<<endl;
    // }
    // for(int i=0;i<=6;i++)
    // {
    //     auto x=upper_bound(a.begin(),a.end(),i);
    //     cout<<x-a.begin()<<endl;
    // }
    cout<<upper_bound(a.begin(),a.end(),-50)-a.begin()<<"  "<<lower_bound(a.begin(),a.end(),-50)-a.begin();
}