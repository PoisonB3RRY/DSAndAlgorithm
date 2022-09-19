#include <stdio.h>

int MaxSubSequenceSum(const int A[], int N);

void main() {
  int A[] = {3, -1, 10, 5, 4, 15, -5, -8};
  int result = MaxSubSequenceSum(A, 8);
  printf("MaxSum is %d\n", result);
}

int MaxSubSequenceSum(const int A[], int N) {
  int MaxSum, ThisSum, i, j;

  for (i = 0; i < N; i++) {
    ThisSum = 0;
    for (j = 0; j < i; j++) {
      ThisSum += A[j];
    }

    if (ThisSum > MaxSum) {
      MaxSum = ThisSum;
    }
  }

  return MaxSum;
}