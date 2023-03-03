#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t min ( size_t x, size_t y ) {
    return x<y ? x : y;
}

//size_t levenshtein_recursive ( char* source, char* target ) {

    // printf( "source=%s\n", source );
    // printf( "target=%s\n", target );

  //  if (strlen(source)==0) return strlen(target);
    //else if (strlen(target)==0) return strlen(source);
    //else if (source[0]==target[0]) return levenshtein_recursive (source+1, target+1);
   // else {
     //   size_t ins = levenshtein_recursive (source+1, target  );
       // size_t del = levenshtein_recursive (source,   target+1);
       // size_t sub = levenshtein_recursive (source+1, target+1);
       // return 1 + min( min(ins,del), sub );
    //}

//}
size_t levMatrix (char* src, char* tgt){
	//acqure values
	size_t srcLen = strlen(src);
	size_t tgtLen = strlen(tgt);

	//matrix for distance
	size_t dist[srcLen + 1][tgtLen+1];

	for(size_t i=0;i<=srcLen; i++){

		dist[i][0]=i;

	}

	for(size_t j = 0; j<=tgtLen; j++){

		dist[0][j]=j;

	}
	//add
	for(size_t i=1; i<= srcLen; i++){

		for(size_t j =1; j<= tgtLen; j++){

			size_t cst = (src[i-1] == tgt[j-1] ? 0 : 1);

			dist[i][j] = min(min(dist[i-1][j] +1, dist[i][j-1]+1), dist[i-1][j-1]+cst);
		}

	}

	return dist[srcLen][tgtLen];

}
int main(int argc, char* argv[])
{

    FILE* inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    char source[32];
    char target[32];

    fscanf (inputFile, "%s\n%s", source, target);

    printf("%ld\n", levMatrix ( source, target ));

    return EXIT_SUCCESS;

}
