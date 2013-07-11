#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;


double maxm(double a,double b){return a>b?a:b;}
double minm(double a,double b){return a>b?b:a;}

int main(int argc,char *agrv[])
{
	double G[9][7],x[9],Ginit[9][7]={
		{4.41,16.40,5.63,113.60,300.70,1036.40,12.20},
		{4.72,14.57,0.39,95.10,184.90,683.70,0.85},
		{1.84,4.47,5.28,148.50,462.30,611.10,6.49},
		{2.69,7.91,0.39,111.00,297.20,632.60,0.92},
		{1.22,3.18,72.04,217.80,816.60,791.10,80.38},
		{1.23,3.16,43.78,179.60,598.20,636.50,48.17},
		{1.12,2.72,65.16,194.70,712.60,634.30,80.17},
		{4.40,9.99,5.35,94.90,245.30,771.70,7.80},
		{2.50,6.21,2.90,94.80,282.10,574.60,1.17}	
	};
	double alpha,max,min,maxtemp2,R[9][9],S[7],temp[9][7],sum1,sum2,sum3,temp2[9],tempag[9][9];
	int i,j,k,m,n,res[9][9];
	cout<<"请输入阈值alpha:"<<endl;
	cin>>alpha;
/***************************
    获取极差标准化矩阵
**************************/
	for(i=0;i<7;i++)
	{
		for(j=0;j<9;j++)
			 x[i] += Ginit[j][i];
		x[i] /= 9;
		for(j=0;j<9;j++)
		{
			S[i] += (Ginit[j][i] - x[i]) * (Ginit[j][i] - x[i]);
		}
		S[i] = sqrt(S[i]/9);
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<7;j++)
		{
			temp[i][j] =(Ginit[i][j]-x[j])/S[j];
		}
	}
	for(i=0;i<7;i++)
	{
		max = temp[0][i];
		min = temp[0][i];
		for(j=0;j<9;j++)
		{
			if(temp[j][i]>max)max = temp[j][i];
			if(temp[i][j]<min)min = temp[j][i];
		}
		for(j=0;j<9;j++)
		{
			G[j][i] = fabs((temp[j][i] - min)/(max-min));
		}
	}
/***************************
     夹角余弦得相似矩阵
**************************/
	for(i=0;i<9;i++)
	{
		for(j=i;j<9&&i<=j;j++)
		{
			sum1=0;sum2=0;sum3 =0;
			for(k=0;k<7;k++)
			{
				 sum1 += G[i][k]*G[j][k];
				 sum2 += G[i][k]*G[i][k];
				 sum3 += G[j][k]*G[j][k];
			}
			R[i][j] = sum1/(sqrt(sum2*sum3));
			R[j][i]=R[i][j];
		}
	}
/***************************
        进行标准化
**************************/
	for(k=0;k<1;k++)
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				maxtemp2 = minm(R[i][0],R[0][j]);
				for(int h=0;h<9;h++)
				{
					temp2[h] =minm(R[i][h],R[h][j]);
					if(maxtemp2 < temp2[h])maxtemp2 = temp2[h];
				}
				tempag[i][j] = maxtemp2;
			}
		}
		for(m=0;m<9;m++)
			for(n=0;n<9;n++)
				R[m][n]  = tempag[m][n];
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(R[i][j]>=alpha)res[i][j]=1;
			else res[i][j]=0;
		}
	}
/***************************
      结果输出 
**************************/
	cout<<"+++++++++++++++++++++"<<endl;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
			printf("%d ",res[i][j]);
		cout<<endl;
	}
	return 0;
}
