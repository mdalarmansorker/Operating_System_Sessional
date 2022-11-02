// Banker's Algorithm
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, i, j, k;
	cout<<"Number of processes: ";
	cin>>n;
	cout<<"Number of resources: ";
	cin>>m;
	int alloc[n][m], max[n][m];
	cout<<"Allocation Matrix:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"P"<<i<<":     ";
		for(j=0;j<m;j++)
		{
			cin>>alloc[i][j];
		}
	}

	cout<<"Max Matrix:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"P"<<i<<":     ";
		for(j=0;j<m;j++)
		{
			cin>>max[i][j];
		}
	}

	int avail[m];
	cout<<"Available Resources: ";
	for(j=0;j<m;j++)
	{
		cin>>avail[j];
	}

	int f[n], ans[n], ind = 0;
	//set all the values of f to zero
	memset(f, 0, sizeof(f));
	int need[n][m];
	//finding out need resources for each process
	cout<<"Need Resources: "<<endl;
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < m; j++)
		{
			need[i][j] = max[i][j] - alloc[i][j];
			cout<<need[i][j]<<" ";
		}
		cout<<endl;
	}
	int y = 0;
	for (k = 0; k < n; k++) 
	{
		for (i = 0; i < n; i++) 
		{
			if (f[i] == 0) //means the ith no process is not allocated yet
			{
				int flag = 0;
				//cheaking p(i) resources if need is not less than available then break otherwise run process i and change available
				for (j = 0; j < m; j++) 
				{
					if (need[i][j] > avail[j])
					{
						flag = 1; //means the ith process is not allocatable
						break;
					}
				}

				if (flag == 0) //means the process resources are allocatable by available resources
				{
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1; //means the process is completed sucessfully
				}
			}
		}
	}

	int flag = 1;

	// To check if sequence is safe or not
	for(int i = 0;i<n;i++)
	{
		if(f[i]==0) //means the ith process is not completed
		{
			flag = 0;
			cout << "The given sequence is not safe"<<endl;
			break;
		}
	}

	if(flag==1) //means no f[i] is not 0
	{
		cout << "Following is the SAFE Sequence" << endl;
		for (i = 0; i < n - 1; i++)
			cout << " P" << ans[i] << " ->";
		cout << " P" << ans[n - 1] <<endl;
	}

	return 0;
}
