#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct bucketSortNode
{
    int order;
    int number;
    struct bucketSortNode *next;
};

typedef struct bucketSortNode *bucket;
typedef struct bucketSortNode *BSNode;


int* bucketSort(int *array, int len);
int max(int arr[], int len);
int getMaxDegree(int number);
void addToLast(int target, bucket b);
int getNumberFromBSNode(bucket b, int position);
void initBucketArray(bucket arr);


void main()
{
    int array[] = {1, 65, 789, 4, 8, 101, 45, 62};
    int len = sizeof(array) / sizeof(int);

    printf("original array len is %d\n", len);

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

    printf("maxDegree is %d\n", maxDegree);

    //复制源数组至临时数组
    int tmpArray[len];
    for (int i = 0; i < len; ++i)
    {
        tmpArray[i] = array[i];
    }

    //构建桶数组，并在每个位置上加入空的头结点
    struct bucketSortNode bsArray[10];
    initBucketArray(bsArray);

    sortCount = 0;

    //开始多次桶排序
    while (sortCount < maxDegree)
    {

        //构建本次排序的零时桶数组,将bsArray拷贝进去
        struct bucketSortNode tempBSNodeArray[10];

        memcpy(tempBSNodeArray, bsArray, 10 * sizeof(struct bucketSortNode));
        initBucketArray(bsArray);

        int index = (int)pow(10, sortCount + 1);
        for (int j = 0; j < len; ++j)
        {
            int order = tmpArray[j] % index;

            addToLast(tmpArray[j], tempBSNodeArray + order);
        }

        memcpy(bsArray, tempBSNodeArray, 10 * sizeof(struct bucketSortNode));

        ++sortCount;
        printf("%d\n", sortCount);
    }

    int resultArray[len];
    int resultArrayCounter;

    for (int i = 0; i < 10; ++i)
    {
        BSNode bPtr;
        bPtr = &bsArray[i];

        while (resultArrayCounter < len)
        {
            if (bPtr->next != NULL)
            {
                resultArray[resultArrayCounter] = bPtr->number;
            }
            ++resultArrayCounter;
        }
    }


    return resultArray;
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

    while (number / 10 != 0)
    {
        ++count;
        number = number / 10;
    }

    result = count + 1;
    return result;
}

//插入链表（桶）尾部
void addToLast(int target, bucket b)
{
    BSNode node;
    node = (struct bucketSortNode *)malloc(sizeof(struct bucketSortNode));

    node->order = b->order;
    node->number = target;
    node->next = NULL;

    while (b->next != NULL)
    {
        ++b;
    }

    b->next = node;

}

int getNumberFromBSNode(bucket b, int position)
{
    for (int i = 0; i < position; ++i)
    {
        ++b;
    }
    return b->number;
}

void initBucketArray(bucket arr)
{
    for (int k = 0; k < 10; ++k)
    {
        BSNode headNode;
        headNode = (struct bucketSortNode *)malloc(sizeof(struct bucketSortNode));
        headNode->number = NULL;
        headNode->order = k;
        headNode->next = NULL;
        memcpy(arr + k, headNode, sizeof(struct bucketSortNode));
    }
}