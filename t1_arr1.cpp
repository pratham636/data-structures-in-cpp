#include<stdio.h>
#include<stdlib.h>

using namespace std;
struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};
void createArray(struct myArray *a,int tsize,int usize)
{
    a->total_size=tsize;
    a->used_size=usize;
    a->ptr=(int*)malloc(tsize * sizeof(int));
}
void show(struct myArray *a)
{int n;
    for(int i=0;i<a->used_size;i++)
    {
        printf("%d\n",(a->ptr)[i]);
    }
}
void setvalue(struct myArray *a)
{
    int n;
    for(int i=0;i<a->used_size;i++)
    {
        printf("Enter number");
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
}
int main()
{
    struct myArray marks;
    createArray(&marks,10,2);
   //cout<<"We are running setVal now"<<endl; 
    setvalue(&marks);
    //cout<<"We are running show now"<<endl;
    show(&marks);
    return 0;
}
