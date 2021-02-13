#include <stdio.h>
#define I 32000
int edge[3][9]={{1,1,2,2,3,4,4,5,5},{2,6,3,7,4,5,7,6,7},{25,5,12,10,8,16,14,20,18}};

int set[8] = {-1,-1,-1,-1,-1,-1,-1,-1};

int included[9] = {0,0,0,0,0,0,0,0,0};

int t[2][6];

void Union(int u, int v)
{
	if(set[u]<set[v])
	{
		set[u] = set[u]+set[v];
		set[v] = u;
	}
	else
	{
		set[v] = set[v]+set[u];
		set[u] = v;
	}
}

int find(int u)
{
	int x=u,v=0;
	while(set[x]>0)
	{
		x = set[x];
	}
	while(u!=x)
	{
		v = set[u];
		set[u] = x;
		u = v;
	}
	return x;
}

int main()
{
	int i=0,j,k,n=7,min=I,u,v;
	while(i<n-1)
	{
		min = I;
		for(j=0;j<=n;j++)
		{
			if(included[j]==0 && edge[2][j]<min)
			{
				min = edge[2][j];
				k = j;
				u = edge[0][j];
				v = edge[1][j];
			}
		}
		if(find(u)!=find(v))
		{
			t[0][i] = u;
			t[1][i] = v;
			Union(find(u),find(v));
			i++;
		}
		included[k] = 1;
	}
	for(j=0;j<n-1;j++)
	{
		printf("(%d,%d)\n",t[0][j],t[1][j]);
	}
	return 0;
}
