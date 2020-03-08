#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int cccc;

void fillr(int *a,int n,int min,int max){

    int i;
    srand(time(0)+cccc);

    for(i=0;i<n;i++){
        a[i]=((rand()%(max-min+1))+min);
    }

}


void merge(int a[],int p,int mid,int q){

    int k=mid,l=q,r=q-p,i;

    int temp[q-p+1];

    while((l>(mid))&&(k>(p-1))){

        if(a[l]>=a[k]){
            temp[r]=a[l];
            r--;
            l--;

        }
        else{
            temp[r]=a[k];
            r--;
            k--;
        }

    }

    while(l>(mid)){
            temp[r]=a[l];
            r--;
            l--;
    }

    while(k>(p-1)){
            temp[r]=a[k];
            r--;
            k--;
    }

    for(i=0;i<q-p+1;i++){
        a[p+i]=temp[i];
    }

}

void mergesort(int *a,int p,int q){

if(q>p){
    int mid=(p+q)/2;
    mergesort(a,p,mid);
    mergesort(a,mid+1,q);
    merge(a,p,mid,q);

}

}

void main(){
    int i,n,m;

    scanf("%d %d",&n,&m);

    int a[n];

    fillr(a,n,0,m);

    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");

    mergesort(a,0,n-1);

    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }



}
