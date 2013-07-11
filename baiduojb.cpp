/*************************************************************************
* File Name: net.cpp
* Author: Bingo
* Mail: Baqiaoyancao@163.com
* Created Time: 2012年06月29日 星期五 20时19分10秒
*************************************************************************/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>
#include <cstdlib>

#define N 1024

using namespace std;
const double precision = 1e-9;
int n,k,D[N];
double dis[N][N];

inline double get_max(double a,double b){return a>b?a:b;}
inline double get_min(double a,double b){return a>b?b:a;}

/***************************
 *check是否有k类,聚类
 * **************************/
int find_anc(int i){return D[i]==i?i:(D[i]=find_anc(D[i]));}
bool check(double mid)
{
	int classnum,i,j,Juge[N];
	memset(Juge,0,sizeof(Juge));
	classnum =0;
	for(i=0;i<n;i++)D[i]=i;
	for(i=0;i<n;i++)
		for(j=0;j<n&&i!=j;j++)
			if(dis[i][j]<mid)
				D[find_anc(i)]=find_anc(j);
	for(i=0;i<n;i++)
		if(!Juge[j=find_anc(i)]){classnum++;Juge[j]=1;}
	return classnum>=k;
}

int main(int argc,char *agrv[])
{
	int i,j,m,l;
	double x[N],y[N],z[N],maxdis,mindis,mid;
	while(scanf("%d %d",&n,&k))
	{
		for(i=0;i<n;i++)scanf("%lf%lf%lf",&x[i],&y[i],&z[i]);
/***************************
 *找出最大最小距离
 * **************************/
		maxdis = 0.0;
		mindis = 10.0;
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				dis[j][i] = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]);
				dis[i][j] = dis[j][i];
				if(dis[i][j]>maxdis) maxdis = dis[i][j];
				if(dis[i][j]<mindis) mindis = dis[i][j];
			}
		}
/***************************
 *处理
 * **************************/
		while(mindis<=maxdis)
		{
			mid = (maxdis+mindis)/2.0;
			if(check(mid)) mindis= mid + precision;
			else maxdis =  mid - precision;
		}
		printf("%.6lf\n",maxdis);
	}
	return 0;
}
