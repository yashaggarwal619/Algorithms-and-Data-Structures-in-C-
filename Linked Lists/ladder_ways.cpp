#include <iostream>
using namespace std;
int steps=0;
int ladder(int n ,int* dp)
{
    if(n<0)
    {
        return 0;
    }

    if(n==0)
    {
        return 1;
    }
   if(dp[n]==-1)
   {
     dp[n]=ladder(n-1,dp)+ladder(n-2,dp)+ladder(n-3,dp);
   }
   else
   {
       return dp[n];
   }


}
int lad2(int n,int k,int *dp)
{
    if(n<0)
    {
        return 0;
    }
    if(n==0)
    {
        return 1;
    }

    if(dp[n]==-1)
    {
        dp[n]=0;
    for(int i=1;i<=k;i++)
    {
         dp[n]+=lad2(n-i,k,dp);

    }
    }
    else
    {
        return dp[n];
    }
    return dp[n];

}
int ways3(int n,int k,int *dp)
{
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {   dp[i]=0;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                dp[i]+=dp[i-j];
            }
        }
    }
    return dp[n];
}
int main()
{
    int dp[10000];
    for(int i=0;i<1000;i++)
    {
        dp[i]=-1;
    }
    cout<<ways3(4,3,dp);

}
