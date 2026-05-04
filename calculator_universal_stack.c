#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_EXPR_LENGTH 100
#define STACK_INCREMENT 10
#define CALC_ERROR -999999.0
#define M_PI 3.14159265358979323846

typedef enum {OK,ERROR}Status;
typedef enum {false = 0,true = 1}bool;

//定义结构体栈
typedef struct {
    void *pBase;//栈底指针
    void *pTop;//栈顶指针（下一个空闲位置，便于压栈操作）
    unsigned int stackSize;//栈的当前容量
    unsigned int elementSize;//栈元素类型的长度
}Stack;


//栈函数

Stack* StackConstruct(unsigned int initSizek,unsigned int elementSize);
/*函数功能：创建并初始化pStack指向的字符栈。
 *输入参数：initSize为栈的初始大小
 *返回值：如果成功，返回OK；如果失败，返回ERROR。
 */
Status StackDestruct(Stack* pStack);
/*函数功能：销毁pStack指向的字符栈。
 *输入参数：pStack指向被初始化的字符栈。
 *返回值：如果成功，返回OK；如果失败，返回ERROR。
 */
int StackLength(Stack* pStack);
/*函数功能：计算pStack所指向的栈长度。
 *输入参数：pStack指向被初始化的字符栈。
 *返回值：如果成功，返回OK；如果失败，返回ERROR。
 */
bool StackIsEmpty(Stack* pStack);
/*函数功能：检查pStack所指向的栈是否为空。
 *输入参数：pStack指向被初始化的字符栈。
 *返回值：如果栈为空，返回true；如果栈不为空，返回false。
 */
Status StackPush(Stack* pStack , void* pElem);
/*函数功能：字符入栈。
 *输入参数：pStack指向被操作的栈，pElem指向被压入的数据元素。
 *返回值：如果成功，返回OK；如果失败，返回ERROR。
 */
Status StackPop(Stack* pStack , void* pElem);
/*函数功能：字符出栈。
 *输入参数：pStack指向被操作的栈，pElem存储弹出的数据元素。
 *返回值：如果成功，返回OK；如果失败，返回ERROR。
 */
Status StackPeek(Stack* pStack ,void* pElem);
/*函数功能：取字符栈的顶部元素。
 *输入参数：pStack指向被操作的栈，pElem存放取出的数据元素。
 *返回值：如果成功，返回OK；如果失败，返回ERROR。
 */
void StackFree(Stack* pStack);
/*函数功能：释放字符栈。
 *输入参数：pStack指向被释放的字符栈。
 *返回值：无。
 */
void StackClear(Stack* pStack);
/*函数功能：清空字符栈。
 *输入参数：pStack指向被清空的字符栈。
 *返回值：无。
 */
Status StackTraverse(Stack*pStack,Status(*visit)());
/*函数功能：遍历栈。
 *输入参数：pStack指向要遍历的字符栈，visit指向操作函数。
 *返回值：如果函数对栈中每个元素操作成功，返回OK，否则返回ERROR。
 */

//应用函数

Status readExpression(char expr[], size_t size);
/*函数功能：从键盘输入表达式expr。
 *输入参数：expr[]为输入的表达式，size为表达式的大小。
 *返回值：如果成功，返回OK；如果失败，返回ERROR。
 */
bool isOperator(char ch);
/*函数功能：判断字符(ch)是否为运算符。
 *输入参数：ch为字符
 *返回值：如果ch是运算符，返回true；如果ch不是，则返回false。
 */
int getPrecedence(char operator);
/*函数功能：得到运算符operator的运算优先级。
 *输入参数：operator为运算符。
 *返回值：返回运算符operator所对应的优先级数字。
 */
bool isUnaryMinus(char expr[], int i);
/*函数功能：判断当前位置的'-'是否为负号（一元运算符）
 *输入参数：expr为表达式字符串，i为当前位置
 *返回值：如果是负号返回true，否则返回false
 */
Status infixToPostfix(char expr[] ,char postfixStr[]);
/*函数功能：将中缀表达式(expr)转换为后缀表达式(postfixStr)。
 *输入参数：中缀表达式(expr),初始的后缀表达式(postfixStr)
 *返回值：如果成功，返回OK；如果失败，返回ERROR。
 */
double evaluatePostfix(char postfixStr[]);
/*函数功能：计算后缀表达式(postfixStr)
 *输入参数：后缀表达式(postfixStr)
 *返回值：返回最终的数字结果。
 */

//实现

//栈函数

// 栈函数实现
Stack* StackConstruct(unsigned int initSize, unsigned int elementSize) {
    Stack *pStack = (Stack*)malloc(sizeof(Stack));
    if (pStack == NULL) return NULL;
    
    pStack->pBase = malloc(initSize * elementSize);
    if (pStack->pBase == NULL) {
        free(pStack);
        return NULL;
    }
    pStack->pTop = pStack->pBase;
    pStack->stackSize = initSize;
    pStack->elementSize = elementSize;
    return pStack;
}

Status StackDestruct(Stack* pStack) {
    if (pStack == NULL) return OK;
    free(pStack->pBase);
    free(pStack);
    return OK;
}

int StackLength(Stack* pStack) {
    return ((char*)pStack->pTop - (char*)pStack->pBase) / pStack->elementSize;
}

bool StackIsEmpty(Stack* pStack) {
    return pStack->pTop == pStack->pBase;
}

Status StackPush(Stack* pStack, void* pElem) {
    if (StackLength(pStack) == pStack->stackSize) {
        unsigned int newSize = pStack->stackSize + STACK_INCREMENT;
        void *pTemp = realloc(pStack->pBase, newSize * pStack->elementSize);
        if (pTemp == NULL) return ERROR;
        pStack->pBase = pTemp;
        pStack->pTop = (char*)pStack->pBase + pStack->stackSize * pStack->elementSize;
        pStack->stackSize = newSize;
    }

    memcpy(pStack->pTop, pElem, pStack->elementSize);
    pStack->pTop = (char*)pStack->pTop + pStack->elementSize;
    return OK;
}

Status StackPop(Stack* pStack, void* pElem) {
    if (StackIsEmpty(pStack)) return ERROR;
    
    pStack->pTop = (char*)pStack->pTop - pStack->elementSize;
    memcpy(pElem, pStack->pTop, pStack->elementSize);
    return OK;
}

Status StackPeek(Stack* pStack, void* pElem) {
    if (StackIsEmpty(pStack)) return ERROR;
    
    void *top = (char*)pStack->pTop - pStack->elementSize;
    memcpy(pElem, top, pStack->elementSize);
    return OK;
}

Status StackTraverse(Stack* pStack, Status (*visit)(void* pElem)) {
    if (pStack == NULL || visit == NULL) {
        return ERROR;
    }
    
    int length = StackLength(pStack);
    char* current = (char*)pStack->pBase;
    
    for (int i = 0; i < length; i++) {
        if (visit(current) == ERROR) {
            return ERROR;
        }
        current += pStack->elementSize;
    }
    
    return OK;
}

// 应用函数实现

Status readExpression(char expr[], size_t size) {
    printf("Please enter the expression: ");
    if (fgets(expr, size, stdin) != NULL) {
        expr[strcspn(expr, "\n")] = '\0';
        return OK;
    }
    return ERROR;
} 

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')';
}

int getPrecedence(char operater) {
    switch (operater) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case 's':
        case 'c':
        case 't': return 3;//函数的优先级最高
        default:  return 0;
    }
}

bool isUnaryMinus(char expr[] , int i){

    if(i==0){
        return true;
    }

    if(expr[i-1] == '('){
        return true;
    }

    if(i > 0 && (expr[i-1] == '+' || expr[i-1] == '-' || 
                  expr[i-1] == '*' || expr[i-1] == '/')){
        return true;
    }
    
    return false;
}
bool isTriFunction(const char* expr, int i) {
    // 检查是否为sin、cos、tan
    if (expr[i] == 's' && expr[i+1] == 'i' && expr[i+2] == 'n') return true;
    if (expr[i] == 'c' && expr[i+1] == 'o' && expr[i+2] == 's') return true;
    if (expr[i] == 't' && expr[i+1] == 'a' && expr[i+2] == 'n') return true;
    return false;
}

Status infixToPostfix(char expr[], char postfixStr[]) {
    // 创建字符栈用于存储运算符
    Stack *opStack = StackConstruct(MAX_EXPR_LENGTH, sizeof(char));
    if (opStack == NULL) {
        printf("Error: Operator stack construction failed!\n");
        return ERROR;
    }
    
    int strIndex = 0;
    printf("Infix expression: %s\n", expr);
    printf("Postfix expression: ");
    
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        
        // 跳过空格
        if (isspace(ch)) {
            continue;
        }
        
        // 处理三角函数
        if (isTriFunction(expr, i)) {
            char funcChar;
            if (ch == 's') {
                funcChar = 's';
                i += 2; // 跳过"in"
            } else if (ch == 'c') {
                funcChar = 'c';
                i += 2; // 跳过"os"
            } else if (ch == 't') {
                funcChar = 't';
                i += 2; // 跳过"an"
            }
            
            StackPush(opStack, &funcChar);
            continue;
        }
        
        // 处理一元负号
        if (ch == '-' && isUnaryMinus(expr, i)) {
            // 在后缀表达式中用'~'表示一元负号
            char unaryMinus = '~';
            // 检查下一个字符是否是数字
            if (isdigit(expr[i + 1]) || expr[i + 1] == '.') {
                // 处理负号后的数字
                postfixStr[strIndex++] = '~';
                postfixStr[strIndex++] = expr[++i]; // 获取负号后的数字
                printf("~%c", expr[i]);
                
                // 继续读取数字的剩余部分
                while (isdigit(expr[i + 1]) || expr[i + 1] == '.') {
                    i++;
                    postfixStr[strIndex++] = expr[i];
                    printf("%c", expr[i]);
                }
                postfixStr[strIndex++] = ' ';
                printf(" ");
            } else {
                // 如果是负号后面是括号或函数，将'~'压入栈
                StackPush(opStack, &unaryMinus);
            }
            continue;
        }
        
        // 处理数字（包括小数）
        if (isdigit(ch) || ch == '.') {
            while (isdigit(expr[i]) || expr[i] == '.') {
                postfixStr[strIndex++] = expr[i];
                printf("%c", expr[i]);
                i++;
            }
            i--;
            postfixStr[strIndex++] = ' ';
            printf(" ");
        }
        // 处理运算符
        else if (isOperator(ch)) {
            if (ch == '(') {
                StackPush(opStack, &ch);
            } else if (ch == ')') {
                char topOp;
                while (!StackIsEmpty(opStack) && StackPeek(opStack, &topOp) == OK && topOp != '(') {
                    StackPop(opStack, &topOp);
                    postfixStr[strIndex++] = topOp;
                    postfixStr[strIndex++] = ' ';
                    printf("%c ", topOp);
                }
                
                if (!StackIsEmpty(opStack)) {
                    StackPop(opStack, &topOp); // 弹出'('
                } else {
                    printf("Error: Mismatched parentheses!\n");
                    StackDestruct(opStack);
                    return ERROR;
                }
            } else {
                char topOp;
                while (!StackIsEmpty(opStack) && StackPeek(opStack, &topOp) == OK && 
                       topOp != '(' && topOp != '~' && // '~'也作为运算符处理
                       getPrecedence(topOp) >= getPrecedence(ch)) {
                    StackPop(opStack, &topOp);
                    postfixStr[strIndex++] = topOp;
                    postfixStr[strIndex++] = ' ';
                    printf("%c ", topOp);
                }
                StackPush(opStack, &ch);
            }
        }
    }
    
    // 将栈中剩余的运算符输出
    while (!StackIsEmpty(opStack)) {
        char topOp;
        StackPop(opStack, &topOp);
        if (topOp == '(') {
            printf("Error: Mismatched parentheses!\n");
            StackDestruct(opStack);
            return ERROR;
        }
        postfixStr[strIndex++] = topOp;
        postfixStr[strIndex++] = ' ';
        printf("%c ", topOp);
    }
    
    postfixStr[strIndex] = '\0';
    printf("\n");
    
    StackDestruct(opStack);
    return OK;
}

double evaluatePostfix(char postfixStr[]) {
    // 创建双精度浮点数栈用于存储数字
    Stack *numStack = StackConstruct(MAX_EXPR_LENGTH, sizeof(double));
    if (numStack == NULL) {
        printf("Error: Number stack construction failed!\n");
        return CALC_ERROR;
    }
    
    for (int i = 0; postfixStr[i] != '\0'; i++) {
        char ch = postfixStr[i];
        
        // 跳过空格
        if (isspace(ch)) {
            continue;
        }
        
        // 处理数字
        if (isdigit(ch) || ch == '.' || (ch == '~' && (isdigit(postfixStr[i + 1]) || postfixStr[i + 1] == '.'))) {
            char numStr[MAX_EXPR_LENGTH];
            int numIndex = 0;
            
            // 处理一元负号
            if (ch == '~') {
                numStr[numIndex++] = '-';
                i++; // 跳过'~'
                ch = postfixStr[i];
            }
            
            // 读取数字
            while (isdigit(ch) || ch == '.') {
                numStr[numIndex++] = ch;
                i++;
                ch = postfixStr[i];
            }
            i--; // 回退一个字符
            
            numStr[numIndex] = '\0';
            double num = atof(numStr);
            StackPush(numStack, &num);
        }
        // 处理一元负号运算符
        else if (ch == '~') {
            double num;
            if (StackLength(numStack) < 1) {
                printf("Error: Insufficient operand for unary minus!\n");
                StackDestruct(numStack);
                return CALC_ERROR;
            }
            StackPop(numStack, &num);
            num = -num;
            StackPush(numStack, &num);
        }
        // 处理三角函数
        else if (ch == 's' || ch == 'c' || ch == 't') {
            double num, result;
            if (StackLength(numStack) < 1) {
                printf("Error: Insufficient operands for function!\n");
                StackDestruct(numStack);
                return CALC_ERROR;
            }
            StackPop(numStack, &num);
            
            // 角度转弧度（三角函数计算的是弧度值）
            double radians = num * M_PI / 180.0;
            
            switch (ch) {
                case 's':  // sin
                    result = sin(radians);
                    break;
                case 'c':  // cos
                    result = cos(radians);
                    break;
                case 't':  // tan
                    if (fabs(cos(radians)) < 1e-10) {
                        printf("Error: Tangent undefined!\n");
                        StackDestruct(numStack);
                        return CALC_ERROR;
                    }
                    result = tan(radians);
                    break;
                default:
                    printf("Error: Unknown function %c!\n", ch);
                    StackDestruct(numStack);
                    return CALC_ERROR;
            }
            StackPush(numStack, &result);
        }
        // 处理二元运算符
        else if (isOperator(ch) && ch != '(' && ch != ')') {
            double n2, n1, result;
            if (StackLength(numStack) < 2) {
                printf("Error: Insufficient operands!\n");
                StackDestruct(numStack);
                return CALC_ERROR;
            }
            StackPop(numStack, &n2);
            StackPop(numStack, &n1);
            
            switch (ch) {
                case '+': 
                    result = n1 + n2; 
                    break;
                case '-': 
                    result = n1 - n2; 
                    break;
                case '*': 
                    result = n1 * n2; 
                    break;
                case '/':
                    if (fabs(n2) < 1e-10) {
                        printf("Error: Division by zero!\n");
                        StackDestruct(numStack);
                        return CALC_ERROR;
                    }
                    result = n1 / n2;
                    break;
                default:
                    printf("Error: Unknown operator %c!\n", ch);
                    StackDestruct(numStack);
                    return CALC_ERROR;
            }
            StackPush(numStack, &result);
        }
    }
    
    // 检查栈中是否只剩下一个结果
    if (StackLength(numStack) != 1) {
        printf("Error: Invalid expression! Stack size: %d\n", StackLength(numStack));
        StackDestruct(numStack);
        return CALC_ERROR;
    }
    
    double finalResult;
    StackPop(numStack, &finalResult);
    StackDestruct(numStack);
    
    return finalResult;
}

int main() {
    char expr[MAX_EXPR_LENGTH];
    char postfixStr[MAX_EXPR_LENGTH * 2];

    readExpression(expr, MAX_EXPR_LENGTH);

    if (infixToPostfix(expr, postfixStr) == OK) {
        double result = evaluatePostfix(postfixStr);
        if (result != CALC_ERROR) {
            printf("Result: %.2f\n", result);
        } else {
            printf("Error: Failed to evaluate expression.\n");
        }
    } else {
        printf("Error: Failed to convert infix to postfix.\n");
    }
    
    return 0;
}