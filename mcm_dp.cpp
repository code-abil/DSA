// #include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
// Check about the complexity of print matrix.
void print(int cost[][100],int start,int end)
{
    if(start==end)
    {
        cout<<start+1;
        return ;
    }
    cout<<"(";
    print(cost,start,cost[end][start]);
    cout<<")(";
    print(cost,cost[end][start]+1,end);
    cout<<")";
}
main()
{
    int n=4;
    int mat[]={40, 20, 30, 10, 30};
    int cost[100][100];
    memset(cost,0,sizeof(cost));

    //Cost of multiplying a matrix with itself is 0.(l=1)
    for(int i=0;i<n;i++)
        cost[i][i]=0;

    for(int len=2;len<=4;len++)
    {
        for(int start=0;start<=4-len;start++)
        {
            int end=start+len-1;
            int _cost=LONG_LONG_MAX;
            int cut_index;
            for(int cut=start;cut<end;cut++)
            {
                if(_cost>cost[start][cut]+cost[cut+1][end]+mat[start]*mat[cut+1]*mat[end+1])
                    cut_index=cut;
                _cost=min(_cost,cost[start][cut]+cost[cut+1][end]+mat[start]*mat[cut+1]*mat[end+1]);
            }
            cost[start][end]=_cost;
            cost[end][start]=cut_index;
            // Lets save some memory.
            // Store the cut_indices in the lower triangular matrix.
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            cout<<cost[i][j]<<" ";
            cout<<endl;
    }
    print(cost,0,n-1);
}