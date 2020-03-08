
#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
#define MIN -100000

int extract_min(int *d,int *a,int n){// returns -1 if a is full else returns the element with min of weights

int i,idx = -1,min = MAX;

for(i=0;i<n;i++){

    if(a[i]==0){
        if(d[i]<min){
            idx = i;
            min = d[i];
        }
    }

}

return idx;
}

void print_dist(int *d,int n,int s){

int i;

for(i=0;i<n;i++){
    if(i!=s){
        printf("d(%d,%d) = %d , ",s+1,i+1,d[i]);
    }
}
printf("\n");

return;
}

void Bellman_Ford(int **w,int n,int e,int s){

int *a;
int *pi;
int *d;
int i,j,q=n;

a= (int *)malloc(n*sizeof(int ));
d= (int *)malloc(n*sizeof(int ));
pi= (int *)malloc(n*sizeof(int ));
a= (int *)malloc(n*sizeof(int ));

for(i=0;i<n;i++){
    d[i] = MAX;
    a[i]=0;
    pi[i] = i;
}

d[s] = 0;
a[s] = 1;

for(i=0;i<n;i++){
    if(w[s][i]!=MIN){
        d[i] = w[s][i];
        pi[i] = s;
    }
}

int v,u;

for(i=0;i<n-1;i++){

    u = extract_min(d,a,n);
    a[u] = 1;

    for(v=0;v<n;v++){
        if((w[u][v]!=MIN)){
            if( w[u][v] + d[u] < d[v] ){
                d[v] = d[u] + w[u][v];
                pi[v] = u;
            }
        }
    }



}



for(i=0;i<n;i++){
	for(j=0;j<n;j++){

		if(w[i][j]!=MIN){
			if(d[j] > d[i] + w[i][j] ){
				printf("the given graph contains negative cycle\n");
				return;
			}
		}

	}
}

print_dist(d,n,s);

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
        weight[i][j] = MIN;
    }
}

printf("give the number of edges in dia-Graph: ");
scanf("%d",&e);
printf("Format of input is \" v_1 v_2 weight(v_1,v_2) \" as 3 integers\n");
printf("index of vertices start from 1\n");
printf("one edge per input for next %d lines\n",e);

for(i=0;i<e;i++){
    scanf("%d %d %d",&v1,&v2,&w);
    weight[v1-1][v2-1]= w;
    //weight[v2-1][v1-1]= w;
}


//printf("Format of input is \" v_1 v_2 weight(v_1,v_2) \" as 3 integers\n");
while(1){

    printf("1.Add edge || 2.Bellman Ford || 3. break\n");
    scanf("%d",&c);


   if(c==1){
        printf("1.Give edge and its weight: ");
        scanf("%d %d %d",&v1,&v2,&w);// need proper input format
        weight[v1-1][v2-1]= w;
       // weight[v2-1][v1-1]= w;
        e++;
   }
   if(c==2){

          printf("Give the source: ");
          scanf("%d",&s);
          if(s<n&&s>0){
              Bellman_Ford(weight,n,e,s-1);
          }
          else{
              printf("wrong input\n");
          }

   }
   if(c==3){
        break;
   }
   if(c!=1&&c!=2&&c!=3){
        printf("wrong input\n");
   }
}


return 0;
}
