#include <stdio.h>
void merge(int a[],int l,int m,int r){
    int t[100],i=l,j=m+1,k=0;
    while(i<=m&&j<=r)t[k++]=a[i]<a[j]?a[i++]:a[j++];
    while(i<=m)t[k++]=a[i++];while(j<=r)t[k++]=a[j++];
    for(i=l,k=0;i<=r;)a[i++]=t[k++];
}
void msort(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        msort(a,l,m);
        msort(a,m+1,r);
        merge(a,l,m,r);}
}
int main(){
    int a[]={12,11,13,5,6,7},n=6;
    msort(a,0,n-1);
    for(int i=0;i<n;i++)printf("%d ",a[i]);puts("");
}
