#include<stdio.h>
#include<stdlib.h>
#include<math.h>


struct node{

int *data;
int level;
struct node* left;
struct node* right;
struct node* parent;

};

struct tree{

struct node* root;

};

void kd_insert(struct tree* T,int* x,int d){

struct node* r;
struct node* p;
int c,i;
r=T->root;

if(T->root==NULL){
    T->root=(struct node*) malloc(sizeof(struct node));
    struct node* Root;
    Root = T->root;
    Root->data =(int*) malloc(d*sizeof(int ));
    for(i=0;i<d;i++){
        Root->data[i]=x[i];
    }
    Root->level = 0;
    Root->right = NULL;
    Root->left = NULL;
    Root->parent = NULL;

    return;
}
else{
    while(r!=NULL){
        p=r;
        if(r->data[(r->level)] > x[(r->level)]){
            r = r->left;
            c=-1;
        }
        else{
            r=r->right;
            c=1;
        }
    }

    if(c==1){
        p->right=(struct node*) malloc(sizeof(struct node));
        r=p->right;
    }
    if(c==-1){
        p->left=(struct node*) malloc(sizeof(struct node));
        r=p->left;
    }


    r->data = (int*) malloc(d*sizeof(int ));
    for(i=0;i<d;i++){
        r->data[i]=x[i];
    }
    r->left=NULL;
    r->right=NULL;
    r->parent = p;
    r->level = (p->level + 1)%d;

    return;
}

}


void inorderwalk(struct node* r,int d){
int i;
if(r!=NULL){
    inorderwalk(r->left,d);
    printf("[");
    for(i=0;i<d;i++){
       printf("%d ",r->data[i]);
    }
    printf("] ");
    inorderwalk(r->right,d);
    return;
}
else{
    return;
}

}


void printtree(struct node* r,int c,int d){

if(r != NULL){
    int i;
    printtree(r->right,c+1,d);
    for(i=0;i<9*c;i++){
        printf(" ");
    }
    printf("[");
    for(i=0;i<d;i++){
       printf("%d ",r->data[i]);
    }
    printf("] ");
    printf("\n");
    printtree(r->left,c+1,d);

}
else{
    printf("\n");
    return;
}
}


int main(){

int i,j,k,d,n;
struct tree* T;
T=(struct tree*) malloc(sizeof(struct tree));
T->root = NULL;
int c=1,*v;

printf("give the \"d\"  of tree: ");
scanf("%d",&d);
v = (int *)malloc(d*sizeof(int));

while(1){

    printf("1.insert \t 2.traverse \t 3.print tree\t 4.exit \n");
    scanf("%d",&c);

    if(c==1){
        printf("give the point to insert : ");


        for(i=0;i<d;i++){
            scanf("%d",&v[i]);
        }
        kd_insert(T,v,d);
    }
    if(c==2){
        inorderwalk(T->root,d);
        printf("\n");
    }
    if(c==3){
           printtree(T->root,0,d);
            printf("\n");
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
