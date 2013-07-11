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
	double x,y;
}point[9],P[3];

int main(int argc,char *agrv[])
{
	int i,j,min,numi,sumix,sumiy,hello;
    double e,tempu[3],totalu,U[9][3],temp3,temp4,temp5,wucha;
	int tempx,tempy,sigu,zeroj;
	e =1.0;

/*************************
 *9组坐标,初始化
 * ************************/
    cout<<"+++++++input+++++++++"<<endl;
	point[0].x =3.0 ;point[0].y =3.0 ;	
	point[1].x =2.0 ;point[1].y =1.0 ;	
	point[2].x =4.0 ;point[2].y =2.0 ;	
	point[3].x =15.0 ;point[3].y =30.0 ;	
	point[4].x =16.0 ;point[4].y =27.0 ;	
	point[5].x =14.0 ;point[5].y =29.0 ;	
	point[6].x =30.0 ;point[6].y =2.0 ;	
	point[7].x =29.0 ;point[7].y =5.0 ;	
	point[8].x =29.0 ;point[8].y =3.0 ;	
	for(i=0;i<9;i++)
		printf("%5.2lf  %5.2lf\n",point[i].x,point[i].y);
	P[0].x = 15.0;P[0].y=10.0;
	P[1].x = 7.0;P[1].y = 8.0;
	P[2].x = 30.0;P[2].y=10.0;

/*************************
 *更新划分矩阵U,软划分
 * ************************/
	while(1)
	{
		for(i=0;i<9;i++)
		{
		    totalu =0.0;sigu=0;
			for(j=0;j<3;j++)
			{
				tempu[j] =(double) ((point[i].x-P[j].x)*(point[i].x-P[j].x) + \
                          (point[i].y-P[j].y)*(point[i].y-P[j].y));
                if(tempu[j]!=0.0) {sigu =0;tempu[j] = 1/tempu[j];totalu += tempu[j];}
                else {sigu=1;zeroj = j;break;}
			}
            if(sigu==1) 
            {
                U[i][zeroj]=1.0;
                for(i=0;j<3;j++)
                {
                    if(j==zeroj)continue;
                    else U[i][j]=0.0;
                }
            }
            else
            {
                for(j=0;j<3;j++)
                    U[i][j] = tempu[j]/totalu;
            }
        }
/*************************
 *更新聚类中心P
 * ************************/
		wucha =0.0;
		for(i=0;i<3;i++)
		{
			numi =0;sumix = 0;sumiy = 0;temp3 =0.0;temp4=0.0;temp5 =0.0;
			tempx = P[i].x;
			tempy = P[i].y;
			for(j=0;j<9;j++)temp3 += U[j][i]*U[j][i];
            for(j=0;j<9;j++)
            {
                temp4 += U[j][i] * U[j][i] * point[j].x;
                temp5 += point[j].y * U[j][i] * U[j][i];
			}	
            if(temp3 !=0)
            {
                P[i].x = temp4/temp3;
			    P[i].y = temp5/temp3;
            }
			wucha +=(P[i].x-tempx)*(P[i].x-tempx)+(P[i].y-tempy)*(P[i].y-tempy);
		}
		if(wucha<=e)break;
	}
    cout<<"++++++聚类中心++++++++"<<endl;
	for(i=0;i<3;i++)printf("%5.2lf %5.2lf\n",P[i].x,P[i].y);
    cout<<"++++++分类结果++++++++"<<endl;
	for(i=0;i<9;i++)
    {
        for(j=0;j<3;j++)
            if(U[i][j]>=0.75) printf("%5d-----%d\n",i,j);
    }
	return 0;
}
