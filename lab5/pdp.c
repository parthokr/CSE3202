#include<stdio.h>

#include <stdlib.h>

#include<sys/types.h>

#include<unistd.h>

#include<pthread.h>

int n = 11, ind = 0;
int arr[10];
void print_array() {
  if (ind == 0)
    printf("array is empty\n");
  else if (ind == n)
    printf("array is full\n");
  else
    for (int i = 0; i < ind; i++) {
      printf("%d", arr[i]);
      printf(" ");
    }
}
void * producer(void *array1) {
 int* array2 = (int*) array1;
  while (1) {
    printf("Hi from producer\n");
    int x = rand() % 100;
    arr[ind++] = x;
    print_array();
    if (ind == n)
      sleep(0);
    printf("\n");
  }
}
void * customer() {
  while (1) {
    printf("Hi from consumer\n");
    if (ind == 0)
      sleep(0);
    else
      //arr[ind]=NULL;
      ind--;
    print_array();
    printf("\n");
  }
}
int main() {
  pthread_t id1, id2;
  int *arr = (int*) malloc(10*sizeof(int));
  pthread_create( & id1, NULL, & producer, arr);
  pthread_create( & id2, NULL, & customer, arr);

  pthread_join(id1, NULL);
  pthread_join(id2, NULL);
  return 0;
}
