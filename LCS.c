#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ele{

int v;
int x;
int y;
char c;

};

int str_len(char * x){

int i=0;

while(x[i]!='\0'){
    i++;
}

return i;

}

// utility function to print the LCS of X[0:startx] and Y[0:strarty]
void print_lcs(struct ele ** a,int m,int n,int startx,int starty){


int p,q;
int vlist[n+m];
char clist[n+m];
int size=0;
int i=startx,j=starty;

while(a[i][j].v!='n'&&a[i][j].x!=-1){

    vlist[size] = a[i][j].v;
    clist[size] = a[i][j].c;
    p = a[i][j].y;
    q = a[i][j].x;
    i=p;
    j=q;
    size++;

}
if(a[i][j].v!='n'){
    vlist[size] = a[i][j].v;
    clist[size] = a[i][j].c;
    size++;
}

for(i=1;i<size;i++){
 vlist[i-1]=vlist[i-1] - vlist[i];
}


for(i=size-1;i>=0;i--){
    if(vlist[i]!=0){
        printf("%c",clist[i]);
    }
}

printf("\n");

return;

}



int LCS(char* x,char* y){
int n,m,i,j;

n = str_len(x);
m = str_len(y);

struct ele ** a;
a = (struct ele **)malloc(m*sizeof(struct ele *));
for(i=0;i<m;i++){
    a[i] = (struct ele *)malloc(n*sizeof(struct ele ));
}

for(i=0;i<m;i++){
    for(j=0;j<n;j++){

        if(i==0){
            if(j==0){
                if(x[j]==y[i]){
                    a[i][j].v=1;
                    a[i][j].x=-1;
                    a[i][j].y=-1;
                    a[i][j].c=x[j];
                }
                else{
                    a[i][j].v=0;
                    a[i][j].x=-1;
                    a[i][j].y=-1;
                    a[i][j].c='n';
                }
            }
            else{
                if(x[j]==y[i]){
                    a[i][j].v=1;
                    a[i][j].x=-1;
                    a[i][j].y=-1;
                    a[i][j].c=x[j];
                }
                else{
                    a[i][j].v=a[i][j-1].v;
                    a[i][j].x=j-1;
                    a[i][j].y=i;
                    a[i][j].c=a[i][j-1].c;
                }
            }
        }
        else{

            if(j==0){
                if(x[j]==y[i]){
                    a[i][j].v = 1;
                    a[i][j].x = j;
                    a[i][j].y = i-1;
                    a[i][j].c = x[j];
                }
                else{
                    a[i][j].v = a[i-1][j].v;
                    a[i][j].x = j;
                    a[i][j].y = i-1;
                    a[i][j].c = a[i-1][j].c;
                }
            }
            else{
                if(x[j]==y[i]){
                    a[i][j].v = a[i-1][j-1].v+1;
                    a[i][j].x = j-1;
                    a[i][j].y = i-1;
                    a[i][j].c = x[j];
                }
                else{

                    if(a[i-1][j].v > a[i][j-1].v){
                        a[i][j].v = a[i-1][j].v;
                        a[i][j].x = j;
                        a[i][j].y = i-1;
                        a[i][j].c = a[i-1][j].c;
                    }
                    else{
                        a[i][j].v = a[i][j-1].v;
                        a[i][j].x = j-1;
                        a[i][j].y = i;
                        a[i][j].c = a[i][j-1].c;
                    }

                }
            }

        }
    }
}

print_lcs(a,m,n,m-1,n-1);

return a[m-1][n-1].v;

}

int main(){

char x[100],y[100];
int i,j;

int lcs,t;
scanf("%d",&t);
while(t>0){
    printf("give the 1st string: ");
    scanf("%s",x);
    i=0;
    while(x[i]!='\0'){
        printf("%c",x[i]);
        i++;
    }
    printf("\n");

    printf("give the 2nd string: ");
    scanf("%s",y);
    i=0;
    while(y[i]!='\0'){
        printf("%c",y[i]);
        i++;
    }
    printf("\n");

    lcs = LCS(x,y);

    printf("%d\n",lcs);
t--;
}
return 0;
}
