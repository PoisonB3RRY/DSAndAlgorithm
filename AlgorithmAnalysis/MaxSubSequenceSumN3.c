#include <stdio.h>

int MaxSubSequenceSum(const int A[], int N);

int MaxSequence[8];
int *p = MaxSequence;

void main() {
  int A[] = {3, -1, 10, 5, 4, 15, -5, -8};
  int result = MaxSubSequenceSum(A, 8);
  printf("MaxSum is %d\n", result);

  int porinter;
  for (porinter = 0; porinter < 8; porinter++) {
    printf("%d,", MaxSequence[porinter]);
  }
  printf("\n");
}

int MaxSubSequenceSum(const int A[], int N) {
  // A为序列，N为序列长度

  int MaxSum, ThisSum, i, j, k;

  MaxSum = 0;

  for (i = 0; i < N; i++) {
    for (j = 0; j < i; j++) {
      ThisSum = 0;
      for (k = j; k <= i; k++) {
        ThisSum += A[k];
      }
      if (ThisSum > MaxSum) {
        MaxSum = ThisSum;
        int l, temp;
        for (l = 0, temp = j; temp <= i; temp++, l++) {
          p[l] = A[temp];
        }
        while (l++ < N) {
          *(p++) = 0;
        }
        p = MaxSequence;
      }
    }
  }

  return MaxSum;
}