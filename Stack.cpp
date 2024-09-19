// Stack ADT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

 #include <iostream>
#include<cstring>
using namespace std;
template <class t>
class Stack_ADT {
private:
    t* stack;
    int size;
    int top;
public:
    Stack_ADT(int size) {
        this->size = size;
        stack = new t[this->size];
        top = -1;
    }
    bool IsEmpty()const {
        return (top == -1);
    }
    bool IsFull() {
        return (top == size - 1);
    }
    void Push(t item) {
        if (IsFull()) {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        stack[top] = item;
    }
   t Pop() {
        if (IsEmpty()) {
            cout << "Stack under flow" << endl;
            return t() ;
        }
        t x = stack[top];
        top--;
        return x;    
    }
   void display() const {
    if(IsEmpty()){
     cout << "Stack under flow" << endl;
            return ;
    }
    else{
        for (int i = top; i >= 0; i--) {
            cout << stack[i] <<endl;
        }
    }
   }
   bool IsBalance(char* p) {
    
       for (int i = 0; i <strlen(p); i++) {
           if (p[i] == '(')
               Push('(');
           else if (p[i] == ')') {
               if (IsEmpty()) {
                   cout << "stack under flow" << endl;
                   return false;
               }
               else {
                   
                t removed= Pop();
               }
           }
       }
    return (IsEmpty());
   }
  bool Is_Operand(t c) {
      if (c == '+' || c == '-' || c == '/' || c == '*' || c == '^') {
          return false;
       }
      return true;
      }
  int Pre(t s) {
      if (s == '+' || s = '-')
          return 1;
      else if (s == '/' || s == '*')
          return 2;
  }
  char*convert_to_postfix(t* infix) {
      t* postfix = new t[sizeof(infix)];
      int i = 0, j = 0;
      while (infix[i] != '\0') {
          if (Is_Operand(infix[i]))
              postfix[j++] = infix[i++];
          else {
              if(Pre(infix[i])>Pre(stack[top]))
                  stack[top++]=infix[i++];
              else {
                 postfix[j++] = Pop();
              }
          }
      }
      while (!IsEmpty()) {
          postfix[j++]=Pop();
      }
      postfix[strlen(postfix) - 1] = '\0';
          return postfix;
  }
  t EvalPost(char* postfix) {
      int x1, x2;
      for (int i = 0; postfix[i] != '\0'; i++) {
          if (Is_Operand(postfix[i])) {
              Push(postfix[i] - '0');
                  
          }
          else {
              x2 = Pop(); x1 = Pop();
              switch (postfix[i]) {
              case '+': Push(x1+x2);
                     break;
              case'-': Push(x1-x2);
                     break;
              case'*': Push(x1*x2);
                     break;
              case'/' :Push(x1/x2);
                    break;
              }
          }
      }
      return stack[top];
  }
  void replaceAllOfEle(t olditem, t newitem) {
      if (IsEmpty()) {
          cout << "Stack under flow" << endl;
          return;
      }
      for (int i = top; i >= 0; i--) {
          if (stack[i] == olditem)
              stack[i] = newitem;
      }
}
  void stackReverse() const {
      if(IsEmpty()){
          cout << "Stack under flow" << endl;
          return;
      }
      Stack_ADT *reverseStack = new Stack_ADT(top + 1);
      for (int i = top; i >=0; i--) 
          reverseStack-> Push(stack[i]);

      for (int i = top; i >=0; i--)
          stack[i] = reverseStack->stack[i];
  
  delete[] reverseStack;
}
  friend Stack_ADT<int> mergeStacks(const Stack_ADT<int>& s1, const Stack_ADT<int>& s2);
  friend Stack_ADT<int> cloneStack(const Stack_ADT<int>& s);
};

bool isStackEmpty(const Stack_ADT<int>& s) {
    return s.IsEmpty();
}
 void printStack(const Stack_ADT<int>& s) {
     s.display();
}
 Stack_ADT<int> mergeStacks(const Stack_ADT<int>& s1, const Stack_ADT<int>& s2) {
     Stack_ADT<int>s3(s1.top + 1 + s2.top + 1);
     for (int i = 0; i <= s1.top; i++) {
         s3.Push(s1.stack[i]);
     }
     for (int i = 0 ; i <= s2.top; i++) {
         s3.Push(s2.stack[i]);
     }
     return s3;
 }
 Stack_ADT<int> ReverseStack(const Stack_ADT<int>& s) {
     s.stackReverse();
     return s;
 }
 Stack_ADT<int> cloneStack(const Stack_ADT<int>& s) {
     Stack_ADT <int> clonedS (s.top+1);
     for (int i = 0; i < clonedS.size; i++){
         clonedS.Push(s.stack[i]);
     }
     
     return clonedS;
 }
int main()
{
   
    char ex[] = { '(', 'a', '+', 'b', ')', '*', '(', 'c', '+','d', ')', '\0' };
    Stack_ADT <char>s1(strlen(ex));
  

   
    if (s1.IsBalance(ex)) 
        cout << "The expression is balanced" << endl;
    
    else 
        cout << "The expression is not balanced" << endl;
    
     char postfix[] = { '3','5','*','6','2','/','+','4','-','\0'}; 
     Stack_ADT <int> s2(strlen(postfix));
    cout<<"the evaluate of the postfix  is = "<<s2.EvalPost(postfix)<<endl;
    
    Stack_ADT <int> s3(3);
    s3.Push(7);
    s3.Push(8);
    s3.Push(6);
    s3.Pop();
    s3.Push(9);
    Stack_ADT <int> s4(4);
    s4.Push(10);
    s4.Push(20);
    s4.Push(30);
    s4.Push(40);
  
    if (isStackEmpty(s3)) {
        cout << "Yes, The stack is empty" << endl;
    }
    else {
        cout << "No, the stack is not empty" << endl;
    }
    cout << "the elements of S3 are :" << endl;
    printStack(s3);
    cout <<"The stack after merged between s3 and s4  is : "<<endl;
    mergeStacks(s3, s4).display();
    cout << "The cloned stack of S3 is :" << endl;
     cloneStack(s3).display();
     cout << "s4 after reverse is :" << endl;
     ReverseStack(s4).display();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
