//Problem Link
//https://atcoder.jp/contests/dp/tasks/dp_a

#include<bits/stdc++.h>
using namespace std;

int minimumcost(int n,vector<int>v)
{
    vector<int>dp(n);
    dp[0]=v[0];
    dp[1]=abs(v[1]-v[0]);

    for(int i=2;i<n;i++)
    {
        dp[i] = min(dp[i-1]+abs(v[i]-v[i-1]),dp[i-2]+abs(v[i]-v[i-2]));
    }
    return dp[n-1];
}

int main()
{
	int n;
	cin>>n;

	vector<int>v;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}

	cout<<minimumcost(n,v);
}