#include<stdio.h>

int select(int a[],int ,int ,int );

void merge(int a[],int l1,int m1,int l2,int m2){
	int k=m1+m2-l1-l2+2;
	int t=k;
	int ans[k],n=m1-l1+1,m=m2-l2+1;

	while(n>0&&m>0){

		if(a[n-1+l1]>a[m-1+l2]){
			ans[k-1]=a[n-1+l1];
			k--;
			n--;
		}
		else{
			ans[k-1]=a[m-1+l2];
			k--;
			m--;
		}

	}

	if(n>0){

		while(n>0){
			ans[k-1]=a[n-1+l1];
			k--;
			n--;
		}
	}
	if(m>0){

		while(m>0){
			ans[k-1]=a[m-1+l2];
			k--;
			m--;
		}
	}

    int i;
	for(i=0;i<t;i++){
		a[i+l1]=ans[i];
	}

}

void merge_sort(int a[],int p,int q){

if(p<q){
	int mid=(p+q)/2;
	merge_sort(a,p,mid);
	merge_sort(a,mid+1,q);
	merge(a,p,mid,mid+1,q);
 	}

}

int partion_rank(int a[],int p,int q,int idx){

	int i,j,temp=a[idx],n=q-p+1;
    a[idx]=a[p];
    a[p]=temp;
    idx=p;

    for(i=1;i<n;i++){
        if(a[p+i]<a[idx]){
                for(j=i;j>idx-p;j--){
                   temp=a[j-1+p];
                    a[j-1+p]=a[j+p];
                    a[j+p]=temp;
                    }
            idx=idx+1;

        }

    }


return idx+1-p;

}


int mid_mid(int a[],int k){

    int arr[k],i,y,x;
    for(i=0;i<k;i++){
        arr[i]=a[i];
    }

   y=(k+1)/2;
   x=select(arr,0,k-1,y);

return x;

}

int m2_location(int *a,int p,int q,int c){

    int n=q-p+1,k=0,i,arr[q-p+1],x;

	for(i=0;i<n;i++){
			arr[i]=a[p+i];
	}
//to sort the set of "c" elements
	while(c*(k+1)<n){

		merge_sort(arr,c*k,c*(k+1)-1);
		k++;

	}
	merge_sort(arr,c*k,n-1);
	k++;
// storing the medians into an array
	int median[k];

	for(i=0;i<k-1;i++){
		median[i]=arr[c*i+((c-1)/2)];
	}
	int temp=(c*k+n-1-c)/2,idx;
	median[k-1]=arr[temp];

    x=select(median,0,k-1,(k+1)/2);

	for(i=0;i<n;i++){
		if(x==a[i+p]){
			idx=i+p;
			break;
		}
	}

return idx;

}


int select(int a[],int p,int q,int stat){

if(q>p){
	int r,idx,temp;

	idx=m2_location(a,p,q,7);//gives the location of m2 in range [p,q]

	temp=a[idx];

	r=partion_rank(a,p,q,idx);//returns rank of a[idx] in a[]

	if(r==stat) return temp;
	if(r>stat) return select(a,p,r-2+p,stat);
	if(r<stat) return select(a,p+r,q,stat-r);

}
else{
    return a[p];
}

}


int main(){
	int n,i,stat,ans;

    scanf("%d %d",&n,&stat);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

    ans=select(a,0,n-1,stat);

	printf("%d is the ans\n",ans);
	return 0;
}
