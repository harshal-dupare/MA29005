#include<stdio.h>
#include<stdlib.h>
#define MAX 100000000

//hor for horizon
struct hor{
int x;
struct hor* next;
};


void print_level(int *level,int n,int s){

int i;

for(i=0;i<n;i++){
    if(i!=s){
        printf("level(%d,%d) = %d , ",s+1,i+1,level[i]);
    }
}
printf("\n");

return;
}

void BFS(int **w,int n,int e,int s){

struct hor* fronter=NULL;
struct hor* temp=NULL;
struct hor* succ=NULL;
int u,v;
int *a;
int *pi;
int i,j,q=n;

a= (int *)malloc(n*sizeof(int ));
pi= (int *)malloc(n*sizeof(int ));

for(i=0;i<n;i++){
    a[i]=-1;
    pi[i] = i;
}

a[s]=0;


fronter =(struct hor*) malloc(sizeof(struct hor));
fronter->x=s;
fronter->next = NULL;

while(fronter!=NULL){

    while(fronter!=NULL){
        u=fronter->x;
        for(i=0;i<n;i++){

            if(w[u][i]!=0){
                if(a[i]==-1){

                    if(succ==NULL){
                        succ = (struct hor*)malloc(sizeof(struct hor));
                        succ->x = i;
                        succ->next=NULL;
                        temp = succ;
                    }
                    else{
                        temp->next = (struct hor*)malloc(sizeof(struct hor));
                        temp=temp->next;
                        temp->x = i;
                        temp->next = NULL;
                    }

                    a[i]=a[u]+1;
                    pi[i]=u;

                }
            }

        }
        fronter=fronter->next;
    }

    fronter = succ;
    succ = NULL;
    temp = NULL;

}


print_level(a,n,s);

return;
}

void explore(int **w,int* a,int* pi,int s,int n){
int i;
for(i=0;i<n;i++){
    if(w[s][i]!=0){
        if(a[i]==-1){
            a[i]=1;
            pi[i]=s;
            explore(w,a,pi,i,n);
        }
    }
}
return;

}

void print_order(int * pi,int n){

for(int i =0 ;i<n;i++){
    printf("pi[%d] = %d, ",i+1,pi[i]+1);
}
printf("\n");
return;
}

void DFS(int **w,int n,int e,int s){

int u,v;
int *a;
int *pi;
int i,j;

a= (int *)malloc(n*sizeof(int ));
pi= (int *)malloc(n*sizeof(int ));


for(i=0;i<n;i++){
    a[i]=-1;
    pi[i] = i;
}

a[s]=1;

explore(w,a,pi,s,n);

print_order(pi,n);

return;
}



int main(){

int n,i,j,c=0,v1,v2,w,e=0,s;

printf("give the number of nodes: ");
scanf("%d",&n);


int** weight;

weight = (int **)malloc(n*sizeof(int *));

// making the weight matrix
for(i=0;i<n;i++){
    weight[i] = (int *)malloc(n*sizeof(int ));
}

for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        weight[i][j] = 0;
    }
}

printf("give the number of edges: ");
scanf("%d",&e);
printf("Format of input is \" v_1 v_2\" as 2 integers\n");
printf("one edge per input for next %d lines\n",e);

for(i=0;i<e;i++){
    scanf("%d %d",&v1,&v2);
    weight[v1-1][v2-1]= 1;
    weight[v2-1][v1-1]= 1;
}


//printf("Format of input is \" v_1 v_2 weight(v_1,v_2) \" as 3 integers\n");
while(1){

    printf("1.Add edge || 2. DFS || 3. BFS || 4. break\n");
    scanf("%d",&c);


   if(c==1){
        printf("1.Give edge: ");
        scanf("%d %d %d",&v1,&v2);// need proper input format
        weight[v1-1][v2-1]= 1;
        weight[v2-1][v1-1]= 1;
        e++;
   }
   if(c==2){
        printf("Give the source: ");
        scanf("%d",&s);
        if(s<=n&&s>0){
            DFS(weight,n,e,s-1);
        }
        else{
            printf("wrong input\n");
        }

   }
   if(c==3){
        printf("Give the source: ");
        scanf("%d",&s);
        if(s<=n&&s>0){
            BFS(weight,n,e,s-1);
        }
        else{
            printf("wrong input\n");
        }
   }
   if(c==4){
        break;
   }
   if(c!=1&&c!=2&&c!=3&&c!=4){
        printf("wrong input\n");
   }
}


return 0;
}
