//Problem Link
//https://atcoder.jp/contests/dp/tasks/dp_b

#include<bits/stdc++.h>
using namespace std;

int minimumcost(int n,int k,vector<int>&v)
{
    if(k>=n)
    {
        return abs(v[n-1]-v[0]);
    }

    vector<int>dp(n,0);
    dp[0]=0;
    for(int i=1;i<=k;i++)
    {
        dp[i]= abs(v[i]-v[0]);
    }

    for(int i=k+1;i<n;i++)
    {
        dp[i]=dp[i-k]+abs(v[i]-v[i-k]);
        for(int j=i-1;j>=i-k;j--)
        {
            dp[i] = min(dp[i],dp[j] + abs(v[i]-v[j]));
        }
    }
    return dp[n-1];
}

int main()
{
	int n,k;
	cin>>n>>k;

	vector<int>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}

	cout<<minimumcost(n,k,v);
}