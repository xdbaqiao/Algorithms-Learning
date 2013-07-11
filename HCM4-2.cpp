#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <set>
#define N 6
#define M N*(N-1)/2
using namespace std;

struct node
{
	double x,y,z;
	int classnum;
}pt[N];

struct info
{
	int posi,posj;
	double value;
}D[M];


int CMP(const void *a,const void * b)
{
	return (*(info *)a).value > (*(info *)b).value ? 1 : -1;
}

int judge()
{
	set<int> s;
	for(int k=0;k<N;k++)
		s.insert(pt[k].classnum);
	return s.size();

}
int main(int argc,char *agrv[])
{
	int i,j,k,temp2,mini,sig,minj,classfy;
	double min,temp;
	k =0;sig =0;
	cin>>classfy;
	temp2 = N;
	for(i =0;i<N;i++){cin>>pt[i].x>>pt[i].y>>pt[i].z;pt[i].classnum = i+1;}
	for(i=0;i<N;i++)
		for(j=i+1;j<N&&i<j;j++)
		{
			D[k].value = (pt[i].x-pt[j].x)*(pt[i].x-pt[j].x)+(pt[i].y-pt[j].y)*(pt[i].y-pt[j].y)+(pt[i].z-pt[j].z)*(pt[i].z-pt[j].z);
			D[k].posi=i;D[k].posj=j;k++;
		}
	qsort(D,k,sizeof(D[0]),CMP);
	if(classfy>N){printf("Error!Please enter the number that is less than N!\n");return 0;}
	cout<<setw(10)<<"X"<<setw(10)<<"Y"<<setw(10)<<"Z";cout<<setw(10)<<"class"<<endl;
	if(classfy==N)
	{
		for(k=0;k<N;k++)
			cout<<setw(10)<<pt[k].x<<setw(10)<<pt[k].y<<setw(10)<<pt[k].z<<setw(10)<<pt[k].classnum<<endl;
		return 0;
	}
	else
	{
		for(int m =0;m<M&&temp2>classfy;m++)
		{
			if(pt[D[m].posj].classnum != pt[D[m].posi].classnum)
			{
				for(k=0;k<m;k++)
					if(pt[D[k].posj].classnum == pt[D[m].posj].classnum)
					{
						pt[D[k].posj].classnum = pt[D[m].posi].classnum;
						pt[D[k].posi].classnum = pt[D[m].posi].classnum;
					}
				pt[D[m].posj].classnum = pt[D[m].posi].classnum;
			}
			temp2 = judge();
		}	
	}
	for(k=0;k<N;k++)
		cout<<setw(10)<<pt[k].x<<setw(10)<<pt[k].y<<setw(10)<<pt[k].z<<setw(10)<<pt[k].classnum<<endl;
	return 0;
}
