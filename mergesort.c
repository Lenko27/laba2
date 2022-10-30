#include <stdio.h>

void mergesort(int s[], int r[], int start, int end)
{
    if (end==start)
        return;
    int mid = (end+start)/2;
    mergesort(s,r,start,mid);
    mergesort(s,r,mid+1,end);
    int i_left, i_right, i_temp;
    i_left = start;
    i_right = mid+1;
    i_temp = 0;
    while ((i_left<=mid) && (i_right<=end))
    {
        if (s[i_left]>s[i_right]) {
            r[i_temp] = s[i_right];
            i_right++;
            i_temp++;
        }
        else {
            r[i_temp] = s[i_left];
            i_left++;
            i_temp++;
        }
    }
    for (int i = i_right; i <= end; i++) {
        r[i_temp] = s[i];
        i_temp++;
    }
    for (int i = i_left; i <= mid; i++) {
        r[i_temp] = s[i];
        i_temp++;
    }

    for (int i=start, g=0; i <= end;i++, g++)
        s[i] = r[g];
}
int main()
{
    int n;
    scanf("%d",n); //error
    int arr[n];
    int temp[n];
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    mergesort(arr,temp,0,n-1);

    for (int i=0;i<n;i++)
        printf("%d ",arr[i]);
}