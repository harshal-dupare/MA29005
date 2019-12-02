#include<stdio.h>
#include<stdlib.h>

int binary_search(int *a,int size,int x){

int max=size ,min=0,flag;

while(max!=min){

    if(x==a[(max+min)/2]){
            flag=(max+min)/2;
            break;}
    if(x>a[(max+min)/2]){
            min=(max+min)/2 +1;}
    if(x<a[(max+min)/2]){
        max=(max+min)/2 -1;}

}

if(max==min){
    if(x=a[min]){
        flag=min;
    }
    else{
        flag=size+1;
    }

}

return flag;

}


void main(){

int n,i;

printf("give the size of array\n");
scanf("%d",&n);

int *a;

a=malloc(n*sizeof(int));

printf("give array\n");
for(i=0;i<n;i++){

    scanf("%d",&a[i]);

}
int key,flag;
printf("give key to search\n");
scanf("%d",&key);

flag=binary_search(a,n,key)+1;

if(flag<=n){
    printf("found at location %d \n",flag);
}
else{
    printf("couldn't find the number in array\n");
}

}
