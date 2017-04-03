#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct
{
 int i;
 int j;
} node;

int a[100];    // Global Array
pthread_attr_t attr;

void *merge_sort(void *param)
{
    node range = *(node *)param, lr, rr;
    pthread_t pt1, pt2;         //Two threads

    int p = range.i, q, r = range.j;
    int n1, n2, n = r-p+1, i, j, k;
    int *al, *ar;     // Two array pointer

    if(p < r)
    {
        q = (p + r) >> 1;
        lr.i = p, lr.j = q, rr.i = q + 1, rr.j = r;

        pthread_create(&pt1, &attr, merge_sort, (void *)&lr);   //  First thread creation
        pthread_create(&pt2, &attr, merge_sort, (void *)&rr);   //  Second thread creation

        pthread_join(pt1, NULL);    // Joining of thread
        pthread_join(pt2, NULL);      // Since in merge sort siblings are independent so we can use concept of  thread here to sort and join them at that level

        n1 = q - p + 1, n2 = r - q;
        al = (int *)malloc(sizeof(int) * n1);
        ar = (int *)malloc(sizeof(int) * n2);

        for(i = 0; i < n1; i++)   //copying half part of data to al
        al[i] = a[p+i];

        for(i = 0; i < n2; i++)   //copying half part of data to ar
        ar[i] = a[q+1+i];

        for(k = i = j = 0; k < n; k++)     // Joining the al and ar
        {
            if(i >= n1 || (j < n2 && al[i] > ar[j]))
            a[k+p] = ar[j++];
            else
            a[k+p] = al[i++];
        }

        free(al);
        free(ar);
    }
    return NULL;
}

int main()
{
    int n, i;
    pthread_t ptd;   // Thread
    node range;
    pthread_attr_init(&attr);  // initializing thread with attr as a parameter


    printf("Enter the size of array \n");
    scanf("%d",&n);

    printf("Enter the array \n");

    for(i = 0; i < n; i++)
      scanf("%d", &a[i]);

    range.i = 0, range.j = n-1;

    pthread_create(&ptd, &attr, merge_sort, (void *)&range);  // (parameters(thread id ,attribute , function name, function parameter)
    pthread_join(ptd, NULL);

    printf("Sorted array is \n");
     for(i = 0; i < n; i++)
       printf("%d%c", a[i], (i==n-1? '\n' : ' '));

    pthread_attr_destroy(&attr);
    return 0;
}
