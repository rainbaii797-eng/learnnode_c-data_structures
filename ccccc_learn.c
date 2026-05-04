# include <stdio.h>
# include <stdlib.h>

// #define MAXSIZE 20

// typedef enum {OK = 1, ERROR = 0} Status;
// typedef enum {true = 1, false = 0} bool;

// typedef int ElemType;

// typedef struct{
//     ElemType data[MAXSIZE];//从0开始
//     int length;//线性表的当前长度是线性表中元素的个数，是会变化的。从一开始。
// }SqList;

// Status InitList(SqList *L);
// /*指针判空：一定要检查传入的指针是否为 NULL
// length 置 0：这是初始化最核心的一步*/
// bool ListEmpty(SqList *L);
// Status ClearList(SqList *L);
// Status GetElem(SqList *L, int i, ElemType *e);
// Status LocateElem(SqList *L, ElemType e);
// Status ListInsert(SqList *L, int i, ElemType e);
// Status ListDelete(SqList *L, int i, ElemType *e);
// int ListLength(SqList *L);

// Status InitList(SqList *L){


//     if(L == NULL){
//         return ERROR;
//     }

//     L->length = 0;

//     return OK;
// }

// bool ListEmpty(SqList *L){

//     if(L == NULL){
//         return false;
//     }

//     if(L->length == 0){
//         return true;
//     }else{
//         return false;
//     }
// }

// Status ClearList(SqList *L){

//     if(L == NULL){
//         return ERROR;
//     }
//     L->length == 0;
    
//     return OK;
// }


// Status GetElem(SqList *L,int i, ElemType *e){
//     if(L == NULL){
//         return ERROR;
//     }

//     if(i<1 || i>L->length){
//         return ERROR;
//     }

//     if(i<=L->length){
//         *e = L->data[i-1];
//         return OK;
//     }
// }

// Status LocateElem(SqList *L, ElemType e){
//     if(L == NULL){
//         return ERROR;
//     }
//     for(int i=0; i<L->length; i++){
//         if(L->data[i] == e){
//             return OK;
//         }
//     }
//     return ERROR;
// }

// int ListLength(SqList *L){
//     return L->length;
// }

// Status ListInsert(SqList *L, int i, ElemType e){
//     //i就是第i个位置，是从一开始算的。
//     if( L->length >= MAXSIZE){
//         return ERROR;
//     }
//     if(i<1 || i>L->length+1){   //这里写成length+1,就可以在末尾也插入了，也就是增加了一个插入的位置。
//         return ERROR;
//     }
//     if(i <= L->length){
//         //j是当作数组中的来看的，是要从0开始的。
//         for(int j=L->length-1; j>=i-1; j--){
//             //j这里取到的范围就是从i-1到length-1,其实就是把在线性表中从第i个开始的都往后挪一个位置。
//             L->data[j+1] = L->data[j];
//         }
//         L->data[i-1] = e;
//         L->length++;
//     }
//     return OK;
// }

// Status ListDelete(SqList *L, int i, ElemType *e){
//     if(L->length == 0){
//         return ERROR;
//     }
//     if(i<1 || i>L->length){
//         return ERROR;
//     }
//     if(i<=L->length){
//         *e = L->data[i-1];
//         for(int j=i; j<L->length; j++){
//             L->data[j-1] = L->data[j];
//         }
//         L->length--;
//     }
//     return OK;
// }

        // Initlist(*L): 初始化操作，建立一个空的线性表L。
        // ListEmpty(L): 判断线性表是否为空表，若线性表为空表，返回true,否则返回false.
        // ClearList(*L): 将线性表清空。
        // GetElem(L,i,*e): 将线性表中的第i个位置元素值返回给e。
        // LocateElem(L,e): 在线性表中查找与给定值e相等的元素，
        //                 如果查找成功，返回该元素在表中序号，表示成功；
        //                 否则，返回0表示失败。
        // ListInsert(*L,i,e): 在线性表中第i个位置插入新元素e.
        // ListDelete(*L, i, *e): 删除线性表L中第i个位置元素，并用e返回其值。
        // ListLength(L): 返回线性表L的元素个数。



// void unionL(SqList *La, SqList Lb){
    
//     int La_len ,Lb_len ;
//     ElemType e;

//     La_len = ListLength(La);
//     Lb_len = ListLength(Lb);

//     for(int i=1; i<Lb_len; i++){

//         GetElem(Lb, i, e);
//         if(!LocateList(*La, e)){
//             ListInsert(La,++La_len,e);
//         }

//     }
// }

// typedef int ElemType;
// typedef enum {OK = 1, ERROR = 0} Status;
// typedef enum {true = 1, false = 0} bool;

// typedef struct Node{
//     ElemType data;//数据域
//     struct Node* Next;//指针域
// } Node;//这是在定义结点，而不是链表。

// //结构体都是类型声明，并不占用内存。(LinkList和Node*都只是类型声明，只有在定义变量时才占用内存。)

// typedef struct Node* LinkList;
// //定义一个类型别名，也就是说之后写的LinkList就相当于在写 Node*;
// //这样定义虽然没有什么实际意义，但是可以在意思上做出区分，比如用Linklist定义链表(头结点),用Node*定义结点。
// //也就是(LinkList == Node*)。


// typedef ElemType e;
// Status LinkInitList(LinkList *L);
// Status LinkListDestory(LinkList *L);
// Status LinkListClear(LinkList L);
// bool ListListIsEmpty(LinkList L);
// int LinkListLength(LinkList L);

// Status GetElem(LinkList L, int i, ElemType *e);
// //在这里的L是定义了链表，但是实际上就是定义了头结点(第零个结点)。
// //这里的i是有数据的结点，是从首元结点开始的。
// //L存储的是头结点的内存地址
// int LocateElem(LinkList L, ElemType e);

// Status LinkListInsert(LinkList L, int i, ElemType e);
// Status InsertHead(LinkList L, ElemType e);
// Status InsertTail(LinkList L, ElemType e);

// Status LinkListDelete(LinkList L, int i, ElemType *e);
// Status DeleteHead(LinkList L, ElemType *e);
// Status DeleteTail(LinkList L, ElemType *e);

// Status LinkListInit(LinkList *L){

//     *L = (LinkList)malloc(sizeof(Node));//头结点定义。

//     if(*L == NULL){
//         return ERROR;
//     }

//     printf("%p\n",*L);

//     (*L)->Next = NULL;

//     return OK;
// }

// Status LinkListDestory(LinkList *L){
//     if(*L == NULL){
//         return ERROR;
//     }

//     Node *p,*q;
//     p = *L;//p指向头结点，从头结点开始释放，后面不用了。
//     while(p != NULL){
//         q = p->Next;
//         free(p);
//         p = q;
//     }
//     *L = NULL;

//     return OK;
// }

// Status LinkListClear(LinkList L){

//     if(L == NULL){
//         return ERROR;
//     }
//     Node *p,*q;
//     p = L->Next;//p指向首元结点，从首元结点开始释放，保留了头结点的内存，后面接着用。
    
//     while(p != NULL){
//         q = p->Next;
//         free(p);
//         p = q;
//     }
//     (L->Next) = NULL;

//     return OK;
// }

// bool LinkListIsEmpty(LinkList L){
//     if(L == NULL){
//         return ERROR;
//     }
    
//     return L->Next == NULL;
// }

// int LinkListLength(LinkList L){

//     if(L == NULL){
//         return 0;
//     }
//     int count=1;
//     Node* p;
//     p = L->Next;
//     while(p != NULL){
//         p = p->Next;
//         count++;
//     }
//     return count;
// }

// int LocateElem(LinkList L, ElemType e){
//     if(L == NULL){
//         return ERROR;
//     }
//     int count = 1;
//     Node *p;
//     p = L->Next;
//     while(p != NULL){
//         if((p->data) == e){
//             return count;
//         }
//         p = p->Next;
//         count++;
//     }
//     return ERROR;
// }

// Status GetElem(LinkList L, int i, ElemType *e){
    
//     if(L == NULL || i<1){
//         return ERROR;
//     }

//     Node* p;
//     p = L->Next;

//     int j=1;
//     while(j<i || p != NULL){
//         p = p->Next;
//         j++;
//     }

//     if(p == NULL){
//         return ERROR;
//     }
    
//     *e = p->data;

//     return OK; 
// }

// Status LinkListInsert(LinkList L, int i, ElemType e){
//     if(L == NULL || i<1){
//         return ERROR;
//     }
//     Node *p = L;
//     for(int j=0; j<i-1; j++){
//         p = p->Next;
//     }

//     if(p == NULL){
//         return ERROR;
//     }
    
//     Node *newnode = (Node*)malloc(sizeof(Node));
//     if(newnode == NULL){
//         return ERROR;
//     }
//     newnode->data = e;

//     newnode->Next = p->Next;
//     p->Next = newnode;

//     return OK;
// }

// Status InsertHead(LinkList L, ElemType e){
//     if(L == NULL){
//         return ERROR;
//     }
//     Node* newnode = (Node*)malloc(sizeof(Node));
//     if(newnode == NULL){
//         return ERROR;
//     }
//     newnode->data = e;
//     newnode->Next = L->Next;
//     L->Next = newnode;
//     return OK; 
// }

// Status InsertTail(LinkList L, ElemType e){


//     if(L == NULL){
//         return ERROR;
//     }
//     Node* newnode = (Node*)malloc(sizeof(Node));
//     if(newnode == NULL){
//         return ERROR;
//     }
//     newnode->data = e;
//     newnode->Next = NULL;

//     if(L->Next == NULL){
//         L->Next = newnode;
//         return OK;
//     }

//     Node* p = L->Next;
//     while(p->Next != NULL){
//         p = p->Next;
//     }
//     p->Next = newnode;

//     return OK;
// }

// Status LinkListDelete(LinkList L, int i, ElemType *e){

//     if(L == NULL || i<1){
//         return ERROR;
//     }
//     Node* p = L;
//     Node* q;

//     for(int j=0; j<i-1 && p != NULL; j++){
//         p = p->Next;
//     }
//     if(p == NULL){
//         return ERROR;
//     }
    
//     if(p->Next == NULL){
//         return ERROR;
//     }
//     q = p->Next;

//     *e = q->data;
//     p->Next = q->Next;
//     free(q);
//     return OK;
// }

// // Status DeleteHead(LinkList L, ElemType *e){
// //     if(L == NULL || L->Next == NULL){
// //         return ERROR;
// //     }
// //     Node* p = L;
// //     Node* q;
// //     q = L->Next;
// //     if(q->Next == NULL){
// //         *e = q->data;
// //         free(q);
// //         return OK;
// //     }
// //     else{
// //         *e = q->data;
// //         p->Next = q->Next;
// //         free(q);
// //         return OK;
// //     }
// // }

// Status DeleteHead(LinkList L, ElemType *e){
//     if(L == NULL || L->Next == NULL){
//         return ERROR;
//     }

//     Node* q = L->Next;
//     *e = q->Next;
//     L->Next = q->Next;
//     free(q);

//     return OK;
// }

// //待修改，下面的代码，记得改，边界检查好难，呜呜呜。
// Status DeleteTail(LinkList L, ElemType *e){
//     if(L == NULL || L->Next == NULL){
//         return ERROR;
//     }
//     Node* p = L;
//     while(((p->Next)->Next) != NULL){
//         p = p->Next;
//     }
//     *e = (p->Next)->data;
//     Node* q = p->Next;
//     p->Next = NULL;
//     free(q);

//     return OK;
// }

// int main(){
    

//     return 0;
// }


//这里释放的是那个被赋值给q的结点的内存，并不是q的内存，所以是在堆上的。
                //而且因为q和p->Next是同一块内存，所以释放q就相当于释放p->Next;

        // *e = (p->Next)->data;
        // free(p->Next);
        // p->Next = p->Next->Next;
        //这样写不对，这样是在访问野指针，所以要找个中间人来。


#define STACK_SIZE 100
typedef int StackElem;
typedef enum {true=1 , false=0} bool;
typedef enum {OK=1 , ERROR=0} Status;

// 用静态数组定义栈
// typedef struct{
//     StackElem a[STACK_SIZE];
//     int top;
//     int stackSize;
// }StaticStack;

// StaticStack *Construct();
// void Destruct(StaticStack* pStack);
// int lengthStack(StaticStack* pStack);
// bool IsEmpty(StaticStack* pStack);
// // Status StackPush(StaticStack* pStack, StackElem e);
// // Status StackPop(StaticStack* pStack, StackElem* e);
// Status Peek(StaticStack* pStack, StackElem* e);
// Status StackTraverse(StaticStack* pStack);
// // void StackClear(StaticStack* pStack);

// StaticStack *Construct(){
//     StaticStack* pStack = (StaticStack*)malloc(sizeof(StaticStack));
//     if(pStack == NULL){
//         return ERROR;
//     }

//     pStack->stackSize = 0;
//     pStack->top = -1;

//     return pStack;
// }

// void Destruct(StaticStack* pStack){
//     free(pStack);
// }

// int lengthStack(StaticStack* pStack){
//     return sizeof(pStack->a)/sizeof(StackElem);
// }

// bool IsEmpty(StaticStack* pStack){
//     return pStack->top<0 ? true:false;
// }

// Status Peek(StaticStack* pStack, StackElem* e){
    
// }

// #include<math.h>

// #define STACK_INIT_SIZE 100
// #define INCREMENT 20

// typedef int ElemType;

// typedef struct{
//     ElemType *base;
//     ElemType *top;
//     int stackSize;
// }Sqstack;

// Status initStack(Sqstack* s){
//     s->base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));

//     // base 是一个指针变量
//     // 它指向的是整个数组的起始地址
//     // 这个起始地址同时也是第一个元素的地址
//     //OK了，其实就跟数组很像了，数组名是整个数组的地址，同时也是第一个元素的地址，好类似。
//     //所以栈的顺序存储结构是用数组来存放数据的，嗯嗯嗯。

//     if(s->base == NULL){
//         return ERROR;
//     }
//     s->top = s->base;//这里是指向了栈底了。
//     //top指向栈顶的下一个元素
//     s->stackSize = STACK_INIT_SIZE;

//     return OK;
// }

// Status StackPush(Sqstack* s, ElemType e){
//     if(s->top - s->base >= s->stackSize ){
//         s->base = (ElemType*)realloc(s->base, (s->stackSize + INCREMENT) * sizeof(ElemType));
//         if(s->base == NULL){
//             return ERROR;
//         }
//         s->top = s->base + s->stackSize;
//         s->stackSize = s->stackSize + INCREMENT;
//     }
//     *(s->top) = e;
//     s->top++;

//     return OK;
// }

// Status StackPop(Sqstack* s, ElemType* e){
//     if(s->top == s->base){
//         return ERROR;
//     }
//     e = s->top - 1;
//     s->top--;
    
//     return OK;
// }

// Status StackClear(Sqstack* s){
//     s->top = s->base;
//     return OK;
// }

// Status StackDestruct(Sqstack* s){
//     if(s == NULL){
//         return ERROR;
//     }
//     if(s->base != NULL){
//         free(s->base);
//         s->base = NULL;
//     }
    
//     s->top = NULL;
//     s->stackSize = 0;

//     return OK;
// }

// bool IsEmpty(Sqstack* s){
//     return s->top == s->base ? true:false;    
// }

// int lengthStack(Sqstack* s){
//     return (s->top - s->base);
// }

// Status StackPeek(Sqstack* s, ElemType* e){   
//     if(s == NULL || e == NULL){
//         return ERROR;
//     }
//     if(s->top == s->base){
//         return ERROR;
//     }
//     *e = *(s->top - 1);

//     return OK;
// }

// Status StackTraverse(Sqstack* s, void(*visit)(ElemType)){
//     if(s == NULL){
//         return ERROR;
//     }
//     if(s->top == s->base){
//         return ERROR;
//     }
//     ElemType* p = s->top;
//     while(p > s->base){
//         p--;
//         visit(*p);
//     }
//     return OK;
// }



// int main(){

// 二进制转化为十进制。

//     ElemType c;
//     Sqstack s;
//     int len;
//     int sum;

//     initStack(&s);
//     printf("please enter the number in two,if enter the # ,  over\n");
//     scanf("%c",&c);
//     while(c != '#'){
//         StackPush(&s, c);
//         scanf("%c",&c);
//     }


//     len = lengthStack(&s);
//     printf("the capacity : %d", len);

//     for(int i=0; i<len; i++){
//         StackPop(&s, &c);
//         sum = sum + (c - 48)*pow(2,i);  // c - 48 将 ASCII 码转换为整数：'0'→0，'1'→1。
//     }

//     printf("after converting: %d", sum);

//     return 0;
// }

//求你了，别抱错了行吗？
//不求你了，继续报错吧。

// #define QUEUE_SIZE 100
// #define INCREMENT_SIZE 20

// typedef int QueueElem;

// typedef struct{
//     QueueElem a[QUEUE_SIZE];
//     int front;
//     int rear;
// }Queue;

// Queue* Construct();
// void Destruct(Queue* q); 
// int Length(Queue* q); 
// bool IsEmpty(Queue* q);
// bool IsFull(Queue* q);
// Status Enter(Queue* q, QueueElem* e);


// Queue* Construct(){
//     Queue* q;
//     q = (Queue*)malloc(sizeof(Queue));
//     if(q == NULL){
//         return NULL;
//     }
//     q->front = 0;
//     q->rear = 0;

//     return q;
// }

// void Destruct(Queue* q){
//     free(q);
//     return ;
// }

// int Length(Queue* q){
//     return (q->rear - q->front + QUEUE_SIZE ) % QUEUE_SIZE;
// }

// bool IsEmpty(Queue* q){
//     return q->front == q->rear ==0;
// }

// bool IsFull(Queue* q){
//     return (q->rear + 1)% QUEUE_SIZE == q->front;
// }

// Status Enter(Queue* q, QueueElem* e){
//     if(IsFull(q)){
//         return ERROR;
//     }
//     q->a[q->rear] = e;
//     q->rear = (q->rear + 1) % QUEUE_SIZE;
//     return OK;
// }

//接下来就是要用链表实现栈和队列了。

typedef void* ElemType;

typedef struct Node{
    void* data;
    struct Node* next;
}Node;

typedef struct LinkedStack{
    Node* top;
    int size;
}LinkedStack;

void InitStack(LinkedStack* s);
void DestroyStack(LinkedStack* s);
bool IsEmpty(LinkedStack* s);
Status Push(LinkedStack* s, ElemType e);
Status Pop(LinkedStack* s, ElemType* e);
Status GetTop(LinkedStack* s, ElemType* e);   

void InitStack(LinkedStack* s){
    s->top = NULL;
    s->size = 0;
}

void DestroyStack(LinkedStack* s){
    Node* cur = s->top;
    while(cur != NULL){
        Node* next = s->top->next;
        free(cur);
        cur = next;
    }
    s->top = NULL;
    s->size = 0;
}

bool IsEmpty(LinkedStack* s){
    return s->top == NULL;
}

Status Push(LinkedStack* s, ElemType e){
    if(s==NULL){
        return ERROR;
    }
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(newnode == NULL){
        return ERROR;
    }
    newnode->data = e;
    newnode->next = s->top;
    s->top = newnode;
    s->size++;

    return OK;
}

Status Pop(LinkedStack* s, ElemType* e){
    if(s==NULL || e==NULL || IsEmpty(s)){
        return ERROR;
    }
    *e = s->top->data;
    Node* p = s->top;
    s->top = s->top->next;
    free(p);

    s->size--;
    return OK;
}

Status GetTop(LinkedStack* s, ElemType* e){
    if(s==NULL || e==NULL || IsEmpty(s)){
        return ERROR;
    }
    *e = s->top->data;
    return OK;
}