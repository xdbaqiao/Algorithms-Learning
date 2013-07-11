#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <sstream>


using namespace std;
int main(int argc,char *agrv[])
{
	int i,j,k;
	double r;
	int point[7][7]={
		{0,0,0,0,0,0,0},
		{2,0,0,0,0,0,0},
		{0,2,0,0,0,0,0},
		{0,0,1,0,0,0,0},
		{0,0,3,0,0,0,0},
		{0,0,0,0,1,0,0},
		{0,0,0,0,0,5,0}
	},D[7];

	cout<<"输入阈值r:";
	cin>>r;
	for(i=0;i<7;i++)D[i]=i;
	for(i=0;i<7;i++)
		for(j=0;j<7&&j<=i;j++)
			if(point[i][j]<=r&&point[i][j]!=0)
			{
				D[i] = D[j];
			}
	cout<<"点 "<<"类别"<<endl;
	for(i=0;i<7;i++)printf("%c  %d\n",'A'+i,D[i]);	

	return 0;
}
