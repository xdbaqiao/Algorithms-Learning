#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>
#include <cstdlib>

using namespace std;

struct node
{
	int x,y;
}point[9],P[3];

int main(int argc,char *agrv[])
{
	int i,j,U[9],min,numi,sumix,sumiy,hello;
	int tempx,tempy,wucha;
	int e;
	e =1;

/*************************
 *9组坐标,初始化
 * ************************/
    cout<<"+++++++input+++++++++"<<endl;
	point[0].x =3 ;point[0].y =3 ;	
	point[1].x =2 ;point[1].y =1 ;	
	point[2].x =4 ;point[2].y =2 ;	
	point[3].x =15 ;point[3].y =30 ;	
	point[4].x =16 ;point[4].y =27 ;	
	point[5].x =14 ;point[5].y =29 ;	
	point[6].x =30 ;point[6].y =2 ;	
	point[7].x =29 ;point[7].y =5 ;	
	point[8].x =29 ;point[8].y =3 ;	
	for(i=0;i<9;i++)
		printf("%5d  %5d\n",point[i].x,point[i].y);
	P[0].x = 15;P[0].y=10;
	P[1].x = 7;P[1].y = 8;
	P[2].x = 30;P[2].y=10;

/*************************
 *更新划分矩阵U
 * ************************/
	while(1)
	{
		for(i=0;i<9;i++)
		{
			U[i]=0;
			min = (point[i].x-P[0].x)*(point[i].x-P[0].x) + \
                  (point[i].y-P[0].y)*(point[i].y-P[0].y);
			for(j=1;j<3;j++)
			{
				hello = (point[i].x-P[j].x)*(point[i].x-P[j].x) + \
                        (point[i].y-P[j].y)*(point[i].y-P[j].y);
				if(hello<min)
				{
					min = hello;
					U[i]=j;
				}
			}
		}
/*************************
 *更新聚类中心P
 * ************************/
		wucha =0;
		for(i=0;i<3;i++)
		{
			numi =0;sumix = 0;sumiy = 0;
			for(j=0;j<9;j++)
			{
				if(U[j]==i) 
				{
					numi++;
					sumix += point[j].x;
					sumiy += point[j].y;
				}
			}	
			tempx = P[i].x;
			tempy = P[i].y;
			if(numi==0)continue;
			P[i].x = (int) (sumix/numi);
			P[i].y = (int) (sumiy/numi);
			wucha + = (P[i].x-tempx)*(P[i].x-tempx) + \
                    (P[i].y-tempy)*(P[i].y-tempy);
		}
		if(wucha<=e)break;
	}
    cout<<"++++++聚类中心++++++++"<<endl;
	for(i=0;i<3;i++)printf("%5d %5d\n",P[i].x,P[i].y);
    cout<<"++++++分类结果++++++++"<<endl;
	for(i=0;i<9;i++)printf("%5d-----%d\n",i,U[i]);
	return 0;
}
