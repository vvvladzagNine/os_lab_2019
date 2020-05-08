#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

static pthread_mutex_t mtx_first = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t mtx_second = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
  int very_complex_data;
} complex_data_t;

static void first_func(complex_data_t* data) {
  printf("Executing first function...\n");
  pthread_mutex_lock(&mtx_first);
  for (int i = data->very_complex_data + 1; i != data->very_complex_data; )
    i++;
  pthread_mutex_lock(&mtx_second);
  for (int i = data->very_complex_data - 1; i != data->very_complex_data; )
    i--;
  pthread_mutex_unlock(&mtx_second);
  pthread_mutex_unlock(&mtx_first);
  printf("Some first function done\n");
}

static void second_func(complex_data_t* data) {
  printf("Executing second function...\n");
  pthread_mutex_lock(&mtx_second);
  for (int i = data->very_complex_data + 1; i != data->very_complex_data; )
    i++;
  pthread_mutex_lock(&mtx_first);
  for (int i = data->very_complex_data - 1; i != data->very_complex_data; )
    i--;
  pthread_mutex_unlock(&mtx_first);
  pthread_mutex_unlock(&mtx_second);
  printf("Some second function done\n");

}

int main(int argc, char* argv[]) {
  pthread_t t1, t2;
  complex_data_t data = {1};

  if (pthread_create(&t1, NULL, (void*)first_func, (void*)&data) != 0) {
    printf("Error: cannot create first thread\n");
    return -1;
  }
  if (pthread_create(&t2, NULL, (void*)second_func, (void*)&data) != 0) {
    printf("Error: cannot create second thread\n");
    return -1;
  }

  if (pthread_join(t1, 0) != 0) {
    printf("Error: cannot join first thread\n");
    return -1;
  }

  if (pthread_join(t2, 0) != 0) {
    printf("Error: cannot join second thread\n");
    return -1;
  }
}
