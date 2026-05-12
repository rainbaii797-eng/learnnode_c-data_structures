#include <stdio.h>
#include <stdlib.h>

typedef enum{true=1,false=0} bool;

/*基于链表实现的队列*/


typedef struct{
    int data;
    ListNode* next;
}ListNode;

typedef struct{
    ListNode *front, *rear;
    int queSize;
}LinkedListQueue;

/*构造函数*/
LinkedListQueue* LinkedListQueueConstruct(){
    LinkedListQueue* queue = (LinkedListQueue*)malloc(sizeof(LinkedListQueue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->queSize = 0;
    return queue;
}

void LinkedlistQueueDeconstruct(LinkedListQueue* queue){
    //释放所有结点
    for(int i=0; i<queue->queSize && queue->front != NULL; i++){
        ListNode* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    //释放queue结构体
    free(queue);
}

/*获取队列的长度*/
int LinkedListQueueSize(LinkedListQueue* queue){
    return queue->queSize;
}

/*判断队列是否为空*/
bool LinkedlistQueueEmpty(LinkedListQueue* queue){
    return size(queue) ==0;
}

/*入队*/
void LinkedlistQueuePush(LinkedListQueue* queue, int e){
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = e;
    
    if(LinkedlistQueueEmpty){
        queue->front = newNode;
        queue->rear = newNode;
        
    }else{
        queue->rear->next = newNode; 
        queue->rear = newNode;
    }
    newNode->next = NULL;
    queue->queSize++;
}

/*访问队首元素*/
int LinkedlistQueuePeek(LinkedListQueue* queue){
    if(queue == NULL || LinkedlistQueueEmpty==0){
        return -1;
    }
    return queue->front->data;
}

/*出队*/
int* LinkedListQueuePop(LinkedListQueue* queue, int* e){
    if(queue == NULL || LinkedlistQueueEmpty==0){
        return NULL;
    }
    *e = queue->front->data;
    ListNode* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    queue->queSize--;
    return e;
}

/*打印队列*/
void printLinkedListQueue(LinkedListQueue* queue){
    int* arr = (int*)malloc(sizeof(int) * queue->queSize);
    //拷贝链表中的数据到数组中
    ListNode* p = queue->front;
    for(int i=0; i<queue->queSize; i++){
        arr[i] = p->data;
        p = p->next;
    }
    for(int j=0; j<queue->queSize; j++){
        printf("%d",arr[j]);
    }
    free(arr);
}



/*基于环形数组实现的队列*/
typedef struct {
    int *nums;    //用于存储队列元素的数组
    int front;    //指向第一个元素(不一定从零开始)，用作索引
    int queSize;     /*指向队尾后一位，此时就可以表示队列长度
                        不是当索引用的*/
    int queCapacity; //队列容量
} ArrayQueue;

ArrayQueue *ArrayQueueConstruct(int capacity){
    ArrayQueue* queue = (ArrayQueue*)malloc(sizeof(ArrayQueue));
    //初始化数组
    queue->queCapacity = capacity;
    queue->front = 0;
    queue->queSize = 0;
    queue->nums = (int*)malloc(sizeof(int) * queue->queCapacity);
    return queue;
}

/*析构函数*/
void ArrayQueueDestruct(ArrayQueue* queue){
    free(queue->nums);
    free(queue);
}

/*获取队列的容量*/
int capacity(ArrayQueue* queue){
    return queue->queCapacity;
}

/*获取队列的长度*/
int size(ArrayQueue* queue){
    return queue->queSize ;
}

/*判断队列是否为空*/
bool empty(ArrayQueue* queue){
    return queue->queSize == 0;
}

/*访问队首元素*/
int peek(ArrayQueue* queue){
    if(empty(queue)){
        return -1;
    }
    return queue->nums[queue->front];
}

/*入队*/
void push(ArrayQueue* queue, int e){
    if(size(queue) == capacity(queue)){
        printf("sorry,haven been full.\n");
        return ;
    }
    //队列数组未满，可能是队列前或者后某一处或者都有位置
    
    //计算队尾指针，指向队尾索引+1
    //通过取余操作实现rear越过数组尾部后回到头部
    int rear = (queue->front + queue->queSize) % queue->queCapacity;
    queue->nums[rear] = e;
    queue->queSize++;
}

/*出队*/
int* pop(ArrayQueue* queue, int* e){
    *e = queue->nums[queue->front];
    queue->front = (queue->front + 1) % queue->queCapacity;
    queue->queSize--;
    return e;
}

