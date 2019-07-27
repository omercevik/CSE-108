#include <stdio.h>

int super_digit(int number);
int rec(int number);

int main(int argc, char const *argv[])
{
  int super = 987697896;
  int temp = super;
  super = rec(super);

  printf("The super digit of %d is %d.\n",temp, super );
  return 0;
}

int rec(int number)
{
  if ( number/10 > 0 )
  {
    number = super_digit(number);
    return rec(number);
  }
  else
    return number;

}

int super_digit(int number)
{
  if (number == 0) {
    return number;
  }
  else
  {
    return number%10 + super_digit(number/10);
  }
}
