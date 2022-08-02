#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<windows.h>

sem_t mutex,Website;
int data = 0,rcount = 0;

void *Worker(void *arg)
{
  int f;
  f = ((int)arg);
  sem_wait(&mutex);
  rcount = rcount + 1;
  if(rcount==1)
   sem_wait(&Website);
  sem_post(&mutex);
  printf("Data read by the Worker%d is %d\n",f,data);
  Sleep(1);
  sem_wait(&mutex);
  rcount = rcount - 1;
  if(rcount==0)
   sem_post(&Website);
  sem_post(&mutex);
  return NULL;
}

void *Manager(void *arg)
{
  int f;
  f = ((int) arg);
  sem_wait(&Website);
  data++;
  printf("Updates done by Manager\n");
  Sleep(1);
  sem_post(&Website);
  return NULL;
}

int main()
{
  int i,b; 
  pthread_t rtid[5],wtid[5];
  sem_init(&mutex,0,1);
  sem_init(&Website,0,1);
  for(i=0;i<=2;i++)
  {
    pthread_create(&wtid[i],NULL,Manager,(void *)i);
    pthread_create(&rtid[i],NULL,Worker,(void *)i);
  }
  for(i=0;i<=2;i++)
  {
    pthread_join(wtid[i],NULL);
    pthread_join(rtid[i],NULL);
  }
  return 0;
}