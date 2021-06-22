#include <stdio.h>
#include <math.h>
int Binary_Search(int T[],int n,int x)
{
	int high=n;
	int low=1;
	int m;
    while(low<=high)
        {
        	m=floor((high+low)/2.0);
            if(x<T[m])
                high=m-1;
            else if(x>T[m])
                low=m+1;
            else
                return m;
        }
    return 0;
}
int main()
{
	int T[100],n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
        scanf("%d",&T[i]);
    scanf("%d",&x);
    printf("%d\n",Binary_Search(T,n,x));
	return 0;
}

