#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int cccc;

void fillr(int a[],int n,int min,int max){

    int i;
    srand(time(0)+cccc);

    for(i=0;i<n;i++){
        a[i]=((rand()%(max-min+1))+min);
    }


}

int max_of_3(int a[],int x,int y,int z){

    if(a[z]>a[x]){
            if(a[z]>a[y]){
                return z;
            }
            else{
                return y;
            }
    }
    else{
            if(a[x]>a[y]){
                return x;
            }
            else{
                return y;
            }

    }

}

int max_of_2(int a[],int x,int y){

    if(a[x]>a[y]){
        return x;
    }
    else{
        return y;
    }

}

int leftnode(int i,int n){// n is index of last element to be in the heap
    // learnt when every thing possible is eliminated what left however impossible is possible
    // it took lot of time to understand that there was problem in left and right node in therms that
    //it was giving one branch lower than what it should have
    if(2*(i+1)<=n+1){
        return 2*i+1;
    }
    else{
        return -1;
    }

}

int rightnode(int i,int n){// returns location of right child in terms of array notation

    if((2*i+3)<=n+1){
        return 2*i+2;
    }
    else{
        return -1;
    }

}

void max_heapify(int a[],int x,int q){

    int idx;
    int temp;

    if((leftnode(x,q)!=-1)&&(rightnode(x,q)!=-1)){
        idx=max_of_3(a,x,leftnode(x,q),rightnode(x,q));

            if(idx!=x){
                temp=a[idx];
                a[idx]=a[x];
                a[x]=temp;
                max_heapify(a,idx,q);
            }

    }
    if((leftnode(x,q)!=-1)&&(rightnode(x,q)==-1)){
        idx=max_of_2(a,x,leftnode(x,q));

        if(idx!=x){
                temp=a[idx];
                a[idx]=a[x];
                a[x]=temp;
                max_heapify(a,idx,q);
        }

    }
}

void build_max_heap(int a[],int p,int q){

    int i;

    for(i=(q/2)+2;i>=p;i--){
        max_heapify(a,i,q);
    }

}

void heapsort(int a[],int p,int q){

    int i,j;
    int temp;
    build_max_heap(a,p,q);
    temp=a[q];
    a[q]=a[p];
    a[p]=temp;

    for(i=q-1;i>=p;i--){
        max_heapify(a,p,i);
        temp=a[i];
        a[i]=a[p];
        a[p]=temp;
        /*printf("%d :: ",i);
        for(j=p;j<q+1;j++){
        printf("%d ",a[j]);
    }
    printf("\n \n");*/
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

   heapsort(a,0,n-1);

    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n\n");

    cccc++;
    t--;
}

}

