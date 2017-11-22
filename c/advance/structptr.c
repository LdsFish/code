#include <stdio.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({			\
        const typeof( ((type *)0)->member ) *__mptr = (ptr);	\
        (type *)( (char *)__mptr - offsetof(type,member) );})

typedef struct {
  char name[20];
  int age;
} Person;

// �H Person ���� age ��쬰�ҡA���� container_of() ��ƪ��@�k
//  container_of(&p.age, Person, age)
//    typeof( ((Person *)0)->age ) is int
//    int *__mptr = (&p.age); 
//    (Person *) ((char *) __mptr - offsetof(Person, age))

int main() {
  Person p = {
    .name="John",
	.age=40
  };
  
  size_t offset = offsetof(Person, age);
  printf("offset=0x%x\n", offset);
  printf("offsetof(Person,age)=0x%x\n", offsetof(Person, age));
  printf("&p=%p\n", &p);
  printf("&p.age=%p\n", &p.age);
  printf("p.age=%d\n", *(&p.age));
  printf("&p+1=%p\n", &p+1);
  printf("&((Person*)&p)[1]=%p\n", &((Person*)&p)[1]);
  char *cptr = (char*) &p;
  printf("cptr+1=%p\n", cptr+1);
  printf("cptr+20=%p\n", cptr+20);
  printf("*(int *)(cptr+20)=%d\n", *(int *)(cptr+20));
  int *mptr = (&p.age);
  printf("(char*)&p+1=%p\n", (char*)&p+1);
  printf("(char*)&p+20=%p\n", (char*)&p+20);
  Person *pptr = (Person *) ((char *) mptr-20);
  printf("pptr=%p\n", pptr);
  printf("container_of(&p.age, Person, age)=%p\n", container_of(&p.age, Person, age));
//  int **agePtr;
//  agePtr  = (int**) (&p+offset);
//  printf("agePtr=%p\n", agePtr);
//  printf("*(&p+offset)=%d\n", *agePtr);
//  printf("&p+offsetof(Person,age)=%p\n", &p+offset);
//  printf("container_of(&p.age,Person,age)=%p\n", container_of(&p.age, Person, age));
}
