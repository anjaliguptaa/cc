#include<stdio.h>
void main()
{
    int a[20][3],i,j,n,temp,tbt=0,r[20],w[20],c=0,ii=0,tq,wait=0,ta[20],taa=0;
    float ath,wait1,taa1;
    printf("we are implementing round robin algorithm \n");
    printf("enter time quanta ");
    scanf("%d",&tq);
    printf(" \n enter no. of processes ");
    scanf("%d",&n);
    printf(" \n enter for process array in the order process no. , arrival time and burst time \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j][1]>a[j+1][1])
            {
              temp=a[j][0];
              a[j][0]=a[j+1][0];
              a[j+1][0]=temp;

              temp=a[j][1];
              a[j][1]=a[j+1][1];
              a[j+1][1]=temp;

              temp=a[j][2];
              a[j][2]=a[j+1][2];
              a[j+1][2]=temp;

            }
        }
    }
    printf("\n as we have all processes arranged according to their arrival time therefore we are implementing the algorithm ... \n");
    for(i=0;i<n;i++)
    {
        tbt=tbt+a[i][2];
        r[i]=a[i][2];
        w[i]=0;
        ta[i]=0;
    }
    ath=(float)n/tbt;
    while(tbt)
    {
        if(r[ii]>0)
        {
            if(r[ii]>tq)
            {
                tbt=tbt-tq;
                c=c+tq;
                r[ii]=r[ii]-tq;
            }
            else
            {
                tbt=tbt-r[ii];
                c=c+r[ii];
                r[ii]=0;
                w[ii]=c-(a[ii][2]+a[ii][1]);
                ta[ii]=c-a[ii][1];
               // wait=wait+w[ii];
                //taa=taa+ta[ii];

            }
        }
        ii=(ii+1)%n;
    }
    for(i=0;i<n;i++)
    {
        wait=wait+w[i];
        taa=taa+ta[i];
    }
    wait1=(float)wait/n;
    taa1=(float)taa/n;
    printf("%d",wait);
printf("\n average waiting time = %f",wait1);
printf("\n average turn around time = %f",taa1);
printf("\n throughput = %f",ath);
}
