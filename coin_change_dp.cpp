#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int sum=11;
    int coins[]={-1,1,5,6,8};
    // -1 being dummy
    int n=4;
    int min_coins[n+1][sum+1];
    // min_cost[index][sum];
    
    //if there are no coins, we can't make any sum out of it
    for(int i=0;i<=sum;i++)
        min_coins[0][i]=LONG_LONG_MAX;

    // if sum==0, we can get the sum with no coins
    for(int i=0;i<=n;i++)
        min_coins[i][0]=0;

    //make sure that min_coins[0][0]=0
    int flag=1;
    for(int i=1;i<=n && flag;i++)
    {
        for(int j=1;j<=sum && flag;j++)
        {
            if(j>=coins[i])
            {
                min_coins[i][j]=min(min_coins[i-1][j],j/coins[i]+min_coins[i-1][j-j%coins[i]]);
                // cout<<min_coins[i-1][j]<<"   "<<1+min_coins[i-1][j-coins[i]]<<endl;
                // cout<<i-1<<" "<<j-coins[i]<<endl;
                // flag=0;
            }
            else
                min_coins[i][j]=min_coins[i-1][j];
        }
    }
    for(int i=1;i<=1;i++)
    {
        for(int j=0;j<=sum;j++)
            cout<<min_coins[i][j]<<" ";
        cout<<endl;
    }
}