#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Used in leveldb

typedef struct key_t{
  int _length;
  char _value[1];
} key;

typedef struct key_other_t{
  int _length;
  char *_value;
} other_key;

int main(){
  key *k1 = (key*)malloc(sizeof(int) + (10 * sizeof(char)));
  // k1 { int _length; char _value[10] };

  key *k2 = (key*)malloc(sizeof(int) + (20 * sizeof(char)));
  // k2 { int _length; char _value[20] };

  printf("%d\n",sizeof(key));

  k1->_length = 10;
  k2->_length = 20;

  strncpy(k1->_value,"Test",k1->_length);
  strncpy(k2->_value,"LongerTestValue",k2->_length);

  printf("%s - %s\n",k1->_value,k2->_value);

  free(k1);
  free(k2);
  
  return 0;
}
