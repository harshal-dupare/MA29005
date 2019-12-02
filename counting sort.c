#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int cccc;
//utility to generate random seq of numbers from given range
void fillr(int *a,int n,int min,int max){

    int i;
    srand(time(0)+cccc);

    for(i=0;i<n;i++){
        a[i]=((rand()%(max-min+1))+min);
    }

}


void counting_sort(int a[],int p,int q,int min,int max){

    int count[max-min+1],i;
// initilix=zig the count array
    for(i=0;i<max-min+1;i++){
        count[i]=0;
    }
//counting the occurance of each element
    for(i=p;i<=q;i++){
        count[a[i]-min]++;
    }
//
    for(i=1;i<max-min+1;i++){
        count[i]+=count[i-1];
    }

    int temp[q-p+1];

    for(i=q;i>=p;i--){
        temp[count[a[i]]-1]=a[i];
        count[a[i]]--;
    }

    for(i=q;i>=p;i--){

     a[i]=temp[i-p];

    }

}

void main(){
    int i,n,m,t;

    scanf("%d %d %d",&t,&n,&m);

    int a[n];

while(t>0){


    fillr(a,n,0,m);

    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");

    counting_sort(a,0,n-1,0,m);

    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n\n");
    cccc++;
    t--;
}

}

