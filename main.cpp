#include <iostream>
#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include <windows.h>
#define MAX 15
typedef char KindData;
using namespace std;

class QueueCircular{

private:
    KindData *V;
    int Front;
    int Rear;

public:
    QueueCircular();
    ~QueueCircular();
    void enqueueCircular(KindData);
    KindData dequeueCircular();
    void machine(int,int,int);
    bool Full();
    bool Empty();
};

QueueCircular::QueueCircular(){
    Front=-1;
    Rear=-1;
    V=new KindData[MAX];
}
QueueCircular::~QueueCircular(){
    delete []V;
}
bool QueueCircular::Empty(){
    if(Rear==-1)
        return true;
    else
        return false;
}
bool QueueCircular::Full(){
    if(Rear==MAX-1)
        return true;
    else
        return false;
}
void QueueCircular::enqueueCircular(KindData X){
    //sleep windows.h

   if ((Front == 0 && Rear == MAX-1) ||(Rear == (Front-1)%(MAX-1))){
        printf("Queue is Full");

    }else if (Front == -1) {
        Front = Rear = 0;
        V[Rear] = X;
    }else if (Rear == MAX-1 && Front != 0){
        Rear = 0;
        V[Rear] = X;
    }else{
        Rear++;
        V[Rear] = X;
    }
}
KindData QueueCircular::dequeueCircular() {
    if (Front == -1){
        printf("\nQueue is Empty");
    }
    int data = V[Front];
    V[Front] = -1;
    if (Front == Rear){
        Front = -1;
        Rear = -1;
    }else if (Front == MAX-1)
        Front = 0;
    else
        Front++;

    return data;

}
void QueueCircular::machine(int aa,int bb,int cc){
    QueueCircular k;
    int A=aa;
    int B=bb;
    int C=cc;
    char a='A';
    char b='B';
    char c='C';
    for(int i=0;i<60;i++){
        if(A==i){
            k.enqueueCircular(a);
            A=0;
            while(!k.Empty()){
            Sleep(4000);
                printf("\n print.[%c].",k.dequeueCircular());
            }
      //  printf("\n A%i ",A+i+5);

        }else if(B==i){
            k.enqueueCircular(b);
            B=0;
            while(!k.Empty()){
            Sleep(4000);
                printf("\n print.[%c].",k.dequeueCircular());
            }

       // printf("\n B%i ",B+i+5);
        }else if(C==i){
            k.enqueueCircular(c);
            C=0;
            while(!k.Empty()){
           Sleep(4000);
                printf("\n print.[%c].",k.dequeueCircular());
            }
        //printf("\n C%i ",C+i+5);
        }

    }
    machine(A+5,B+5,C+5);

}
int main(){

    int N;
    int n;
    int a,b,c;
    srand((unsigned)time(NULL));
    cout<<"Queue Circular ";
    //cout << "\ncuantos datos? ";
    //std::cin>>n;
    QueueCircular k;
    printf("\nTiempo a Maquina A: ");
    std::cin>>a;
    printf("\nTiempo a Maquina B: ");
    std::cin>>b;
    printf("\nTiempo a Maquina C: ");
    std::cin>>c;
    k.machine(a,b,c);
    /*for (int i = 0; i <=n ; ++i) {
        int data=rand()%100+1;
        printf("\ndato %i almacenado :%i ",i,data);
        //std::cin>>N;

        k.enqueueCircular(data);
        Sleep(3000);
    }
    */
    //printf("\n");

    /*
    while(!k.Empty()){
        printf("\n.[%c].",k.dequeueCircular());
    }*/
   // system("pause");
    return 0;
}
