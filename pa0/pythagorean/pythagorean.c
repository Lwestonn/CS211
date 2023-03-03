#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {

  // Open the filename given as the first command line argument for reading
  FILE* fp = fopen(argv[1], "r");
  if (!fp) {
    perror("fopen failed");
    return EXIT_FAILURE;
  }
  

  char buf[256];
//num1 from tester
  char* string = fgets(buf, 256, fp);
  int x = atoi(string);
//num2
  char* string2 = fgets(buf, 256, fp);
  int num = atoi(string2);

  // Printing in C.
  // %d is the format specifier for integer numbers.
  // \n is the newline character
  int hyp = sqrt(pow(x,2) + pow(num,2));

   if(pow(hyp,2)==pow(x,2)+pow(num,2)){

	printf("%d\n",hyp);

   }else {

	if(x>num){

	 int temp =x;

	 x=num;

	 num=temp;

		}
	
	hyp= sqrt(pow(num,2)-pow(x,2));

	if(pow(hyp,2)==pow(num,2)-pow(x,2)){

			printf("%d\n",hyp);

		}else if(pow(hyp,2)==pow(x,2)+pow(num,2)){

				printf("%d\n",hyp);

			}else{

		//print for not a triplet
		printf("-1\n");
	}
   }
  
  return EXIT_SUCCESS;

}
