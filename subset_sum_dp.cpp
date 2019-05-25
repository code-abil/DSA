#include<bits/stdc++.h>
using namespace std;
#define int long long
// Considering that we call the below function only when we have a soln.
void print_values(int val[],int subset[][100],int i,int j)
{
    if(subset[i][j]==0)
    {
        cout<<"No possible subset\n";
        return;
    }
    if(i==0 || j==0)    
        return ;
    if(subset[i-1][j]==1)
        print_values(val,subset,i-1,j);
    else
    {
        cout<<val[i]<<" ";
        print_values(val,subset,i-1,j-val[i]);
    }
    
}
main()
{
    int sum=11;
    int n=5;
    int val[]={-1,2,3,7,8,10};
    // first element being a dummy.
    int subset[100][100];
    
    // Matrix being built is of the form
    // col:sum,row:val
    // subset[val][sum]
    // Corner cases can be : having sum as 0.
    
    // With no values, we can't get any sum.
    for(int i=0;i<=sum;i++)
        subset[0][i]=0;
    
    // With sum as 0, we can achieve the sum as we build a empty subset
    for(int i=0;i<=n;i++)
        subset[i][0]=1;
    //subset[0][0]=1 (As we can build a empty subset which totals to 0.)

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j>=val[i])
                subset[i][j]=subset[i-1][j]||subset[i-1][j-val[i]];
            else
                subset[i][j]=subset[i-1][j];
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
            cout<<subset[i][j]<<" ";
            cout<<endl;
    }
    print_values(val,subset,n,sum);
}