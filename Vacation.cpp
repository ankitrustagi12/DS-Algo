#include<bits/stdc++.h>
using namespace std;

int maximumpoints(int n,int arr[][3])
{
	int dp[n][3];

	dp[0][0]=arr[0][0];
	dp[0][1]=arr[0][1];
	dp[0][2]=arr[0][2];

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(j==0)
			{
				dp[i][j]=arr[i][j]+max(dp[i-1][j+2],dp[i-1][j+1]);
			}
			else if(j==1)
			{
				dp[i][j]=arr[i][j]+max(dp[i-1][j+1],dp[i-1][j-1]);
			}
			else
			{
				dp[i][j]=arr[i][j]+max(dp[i-1][j-2],dp[i-1][j-1]);
			}
		}
	}
    return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
}

int main()
{
	int n;
	cin>>n;

	int arr[n][3];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	}

	cout<<maximumpoints(n,arr);
}