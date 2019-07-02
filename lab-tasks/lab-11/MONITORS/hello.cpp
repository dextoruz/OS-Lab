#include <pthread.h>
#include <iostream>

using namespace std;



class C
{
  int val = 0;
public:
    void *hello(int x)
    {
        std::cout << "Hello, world!" <<x<< std::endl;
        val = x;
        return 0;
    }

    // static void *hello_helper(void *context)
    // {
    //     return ((C *)context)->hello(12);
    // }
    void printVal(){
      cout<<val<<endl;
    }
};

struct argu{
  C c;
  int num;
};

class A {

public:
  static void *hello_helper(void *context)
  {
    ((argu *)context)->c.hello(((argu *)context)->num);

  }
};

int main(){

  A a;
  C *c;
  argu argument;
  c = &argument.c;
  int x = 12;
  argument.num = x;
  pthread_t t;
  pthread_create(&t, NULL, &a.hello_helper, &argument);
  pthread_join(t, NULL);
  c->printVal();
  // c.printVal();
  return 0;
}
