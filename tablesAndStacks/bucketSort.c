#include <stdio.h>
#include <stdlib.h>

int* bucketSort(int *array, int len);
int max(int arr[], int len);
int getMaxDegree(int number);

struct bucketSortNode
{
    int degree;
    int number;
    bucketSortNode *next;
} *BSNode;

typedef struct bucketSortNode *bucket;

void main()
{
    int array[] = {1, 65, 789, 4, 8, 101, 45, 62};
    int len = sizeof(array) / sizeof(int);

    int* result;
    result = bucketSort(array, len);

    for (int i = 0; i < len; ++i)
    {
        printf("%d ", *result);
    }
}

int* bucketSort(int array[], int len)
{
    int maxDegree, sortCount;
    maxDegree = getMaxDegree(max(array, len));

    //复制源数组至临时数组
    int tmpArray[len];
    for (int i = 0; i < len; ++i)
    {
        tmpArray[i] = array[i];
    }

    //构建桶数组
    struct BSNode bsArray[10];

    //开始多次桶排序
    while (sortCount < maxDegree)
    {
        int index = (int)pow(10, sortCount + 1);
        for (int j = 0; j < 10; ++j)
        {
            int order = tmpArray[j] % index;


        }

        ++sortCount;
    }

    sortCount = 0;
    while (sortCount < maxDegree)
    {
        //排序


    }

    return NULL;
}

int max(int array[], int len)
{
    int max;
    int *ptr;

    ptr = array;
    max = *ptr;
    for (int i = 0; i < len; ++i)
    {
        if (max < array[i])
        {
            max = array[i];
        }
    }
    return max;
}

int getMaxDegree(int number)
{
    int result, count;

    count = 0;

    while (number % 10 != 0)
    {
        count++;
        number = number % 10;
    }

    result = count + 1;
    return result;
}

//插入链表（桶）尾部
void addToLast(int target, bucket b)
{
    BSNode node;
    node = malloc(sizeof(struct bucketSortNode));

    node->order = b->order;
    node->number = target;
    node->next = NULL;
}